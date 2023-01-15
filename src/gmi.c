// #include "network.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "gmi.h"
#include "log.h"

enum gmi_mode gmi_mode = GMI_MODE_UNDETECTED;
unsigned int gmi_tdm_kills[] = {0, 0};

void gmi_mode_detect_message(char* message) {
	char* lower = malloc(sizeof(char) * strlen(message) + 1);
	for(unsigned int i = 0; *(message + i) != '\0'; i++) {
		lower[i] = tolower(message[i]);
	}

	lower[strlen(message)] = '\0';

	char* ptr;
	if((ptr = strstr(lower, "game mode: ")) != NULL) {
		ptr += 11;
	} else if((ptr = strstr(lower, "gamemode: ")) != NULL) {
		ptr += 10;
	} else {
		goto end;
		return;
	}

	if(!strcmp(ptr, "arena") || !strcmp(ptr, "arena by yourself")) { gmi_mode = GMI_MODE_ARENA; }
	else if(!strcmp(ptr, "babel")) { gmi_mode = GMI_MODE_BABEL; }
	else if(!strcmp(ptr, "tdm")) { gmi_mode = GMI_MODE_TDM; }
	else {
		gmi_mode = GMI_MODE_UNKNOWN;
		log_info("unknown mode %s", ptr);
		goto end;
	}

	log_info("DETERMINED GAMEMODE: %s", ptr);

end:
	free(lower);
}

void gmi_parse_tdm(char* message) {

}