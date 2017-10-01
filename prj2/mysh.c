#include <stdio.h>
#include <string.h>
#include <stdint.h>


#define NUM_COMMANDS sizeof(commands)/sizeof(command_t)

#define COMMAND_ENTRY(_name, _fp)\
	const command_t __attribute__((section (".commands"))) cmd_##_fp = \
	{\
		.name = _name,\
		.fp = _fp\
	};


typedef struct command {
	const char *name;
	command_status (*fp)(int argc, char *argv[]);
} command_t;

command_t commands[4];

COMMAND_ENTRY("ls", "ls does this", "", /bin/ls);
COMMAND_ENTRY("ls", "ls does this", "", /bin/ls);
COMMAND_ENTRY("ls", "ls does this", "", /bin/ls);
COMMAND_ENTRY("ls", "ls does this", "", /bin/ls);

uint16_t get_command_index(char *commandName) {
	for(int i = 0, i < NUM_COMMAND, i++) {
		if(!strcmp(commands[i], commandName)) {
			return i;
		}
	}
}

void processInput(char * buff) {
	char * argv[4];
	char * str = NULL;
	uint16_t i = 1;

	str = strtok(buff, " ");
	argv[0] = str;
	get_command_index(argv[0]);

		printf("%s", str);
	while(str != NULL) {
		str = strtok(NULL, " ");
		argv[i] = str;
		printf("%s", str);
		i++;
	}

	commands[command_index].fp(args_index, args);


}

int main() {
	char * buff = NULL;
	size_t size = 0;

	for(;;) {
		printf("-> ");
		getline(&buff, &size, stdin);
		processInput(buff);
	}

	return 0;
}
