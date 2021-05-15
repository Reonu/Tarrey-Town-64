static const s16 toad2_anim_ToadBuilding_values[] = {
	0xFFFB, 0x0000, 0x0007, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 
	0xFFFF, 0x0027, 0x0083, 0x00EA, 0x012C, 0x011A, 0x008D, 0xFF68, 0xFDC1, 
	0xFC0F, 0xFB46, 0xFB46, 0xFB46, 0xFB46, 0xFB46, 0xFB46, 0xFBA5, 0xFC94, 
	0xFDC1, 0xFEE6, 0xFFDA, 0x008D, 0x00FB, 0x012C, 0x012C, 0x0106, 0x00C9, 
	0x0083, 0x0041, 0x0012, 0xFFFF, 0x0000, 0xFECC, 0xFB7B, 0xF675, 0xF032, 
	0xE947, 0xE260, 0xDC28, 0xD737, 0xD3FD, 0xD2D6, 0xD2D6, 0xD2D6, 0xD2D6, 
	0xD2D6, 0xD2D6, 0xD35C, 0xD4DA, 0xD737, 0xDA58, 0xDE1D, 0xE260, 0xE6F1, 
	0xEB9E, 0xF032, 0xF47B, 0xF84B, 0xFB7B, 0xFDE8, 0xFF74, 0x0000, 0x0000, 
	0x005C, 0x0155, 0x02C5, 0x0491, 0x06AB, 0x0913, 0x0BC5, 0x0E9D, 0x1113, 
	0x1223, 0x1223, 0x1223, 0x1223, 0x1223, 0x1223, 0x11A4, 0x105A, 0x0E9D, 
	0x0CB8, 0x0AD8, 0x0913, 0x0770, 0x05EF, 0x0491, 0x0355, 0x023F, 0x0155, 
	0x009F, 0x002A, 0x0000, 0xC419, 0x0EAC, 0xF850, 0x0000, 0xFFFF, 0xFFFF, 
	0xC291, 0xC291, 0xC291, 0xC291, 0xC291, 0xC291, 0xC291, 0xC4FB, 0xCBB4, 
	0xD5F8, 0xE28F, 0xEFC0, 0xFBC6, 0x054A, 0x0B73, 0x0DA7, 0x0DA7, 0x0DA7, 
	0x0DA7, 0x0DA7, 0x0DA7, 0x0C0C, 0x078B, 0x0091, 0xF795, 0xED39, 0xE24C, 
	0xD7C3, 0xCE88, 0xC751, 0xC291, 0xC013, 0xBF04, 0xBEBF, 0xBECD, 0xBEE3, 
	0xBF5C, 0xC05A, 0xC164, 0xC237, 0xC291, 0xF12F, 0xF12F, 0xF12F, 0xF12F, 
	0xF12F, 0xF12F, 0xF12F, 0xF16A, 0xF243, 0xF418, 0xF722, 0xFAF9, 0xFEB5, 
	0x0190, 0x0344, 0x03D6, 0x03D6, 0x03D6, 0x03D6, 0x03D6, 0x03D6, 0x035C, 
	0x01F8, 0xFFAF, 0xFCA2, 0xF92E, 0xF5E9, 0xF35F, 0xF1CE, 0xF125, 0xF12F, 
	0xF505, 0xFDDD, 0x0872, 0x1128, 0x14B9, 0x111E, 0x084E, 0xFD9F, 0xF4CC, 
	0xF12F, 0x081D, 0x081D, 0x081D, 0x081D, 0x081D, 0x081D, 0x081D, 0x076F, 
	0x059F, 0x032F, 0x00F1, 0xFFB6, 0xFFBB, 0x0085, 0x015E, 0x01BB, 0x01BB, 
	0x01BB, 0x01BB, 0x01BB, 0x01BB, 0x0170, 0x00B7, 0xFFE9, 0xFF7A, 0xFFD2, 
	0x011B, 0x0315, 0x053E, 0x070C, 0x081D, 0x086D, 0x0822, 0x0795, 0x0721, 
	0x06F4, 0x0740, 0x07C2, 0x0814, 0x0824, 0x081D, 0xFFFF, 0x0000, 0xFFFF, 
	
};

static const u16 toad2_anim_ToadBuilding_indices[] = {
	0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001, 
	0x0004, 0x0001, 0x0005, 0x0001, 0x0006, 0x0001, 0x0007, 0x0001, 0x0008, 
	0x001F, 0x0009, 0x001F, 0x0028, 0x001F, 0x0047, 0x0001, 0x0066, 0x0001, 
	0x0067, 0x0001, 0x0068, 0x0001, 0x0069, 0x0001, 0x006A, 0x0001, 0x006B, 
	0x0029, 0x006C, 0x0029, 0x0095, 0x0029, 0x00BE, 0x0001, 0x00E7, 0x0001, 
	0x00E8, 0x0001, 0x00E9, 
};

static const struct Animation toad2_anim_ToadBuilding = {
	0,
	0,
	0,
	1,
	40,
	ANIMINDEX_NUMPARTS(toad2_anim_ToadBuilding_indices),
	toad2_anim_ToadBuilding_values,
	toad2_anim_ToadBuilding_indices,
	0,
};
