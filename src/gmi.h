enum gmi_mode {
	GMI_MODE_UNDETECTED,
	GMI_MODE_UNKNOWN,
	GMI_MODE_ARENA,
	GMI_MODE_BABEL,
	GMI_MODE_TDM
};

extern enum gmi_mode gmi_mode;
extern unsigned int gmi_tdm_kills[2];
void gmi_mode_detect_message(char* message);