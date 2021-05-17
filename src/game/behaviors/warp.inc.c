// warp.c.inc

void bhv_warp_loop(void) {
    u16 sp6;
    if (o->oTimer == 0) {
        sp6 = (o->oBehParams >> 24) & 0xFF;
        if (sp6 == 0)
            o->hitboxRadius = 50.0f;
        else if (sp6 == 0xFF)
            o->hitboxRadius = 10000.0f;
        else
            o->hitboxRadius = sp6 * 10.0;
        o->hitboxHeight = 50.0f;
    }
    o->oInteractStatus = 0;
}

void bhv_fading_warp_loop() // identical to the above function except for o->hitboxRadius
{
    u16 sp6;
    if (o->oTimer == 0) {
        sp6 = (o->oBehParams >> 24) & 0xFF;
        if (sp6 == 0)
            o->hitboxRadius = 85.0f;
        else if (sp6 == 0xFF)
            o->hitboxRadius = 10000.0f;
        else
            o->hitboxRadius = sp6 * 10.0;
        o->hitboxHeight = 50.0f;
    }
    o->oInteractStatus = 0;
}

void bhv_warp_stalker_loop() {
    if (gMarioState->floor != NULL) {
            if ((gMarioState->floor->force & 0xFF) == 0x0A) {
                if((gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_MOVING) {
                    o->oPosX = (gMarioState->floor->vertex1[0] + gMarioState->floor->vertex2[0] + gMarioState->floor->vertex3[0]) / 3;
                    o->oPosY = ((gMarioState->floor->vertex1[1] + gMarioState->floor->vertex2[1] + gMarioState->floor->vertex3[1]) / 3) + 50;
                    o->oPosZ = (gMarioState->floor->vertex1[2] + gMarioState->floor->vertex2[2] + gMarioState->floor->vertex3[2]) / 3;
                    o->oFaceAngleYaw = gMarioState->faceAngle[1];
                }
            }
     }
     /*if (gDead) {
         gMarioState->health = 0x800;

         gMarioState->pos[0] = o->oPosX;
         gMarioState->pos[1] = o->oPosY;
         gMarioState->pos[2] = o->oPosZ;

        gMarioState->marioObj->oPosX = gMarioState->pos[0];
        gMarioState->marioObj->oPosY = gMarioState->pos[1];
        gMarioState->marioObj->oPosZ = gMarioState->pos[2];

        gMarioObject->header.gfx.pos[0] = gMarioState->pos[0];
        gMarioObject->header.gfx.pos[1] = gMarioState->pos[1];
        gMarioObject->header.gfx.pos[2] = gMarioState->pos[2];

        
        gMarioState->action = ACT_IDLE;
        gDead = 0;
     }*/
}