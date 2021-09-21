#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Keymap {
  int key;
  char * value;
}Keymap;

void seperate(char* str,char* deli, int count, char ** stage)
{

  // char* list[count];
  char *res = NULL;
  res = strtok( str, deli );
  for(int i = 0; i < count;i++){
    stage[i] = res;
    res = strtok(NULL, deli);
  }
}


int main(int argc, char* argv[]){
	if (argc == 1){
		printf("Command line should start with p, g, a, c, d.\n");
		exit(1);
	}


  //initial database
  int size = 2000;
  int num = 0;
  Keymap* kvStorage[size];
  char* deli = ",";
  char* command;
  int count;
  int exist;
  int key;
  char* value;
  int index;

  FILE *data;
    data = fopen("database.txt", "r");

  if(data){
	fscanf(data, "%d", &size);
	fscanf(data, "%d", &num);

    size =2000;
    num =10;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    getline(&line, &len, data);
    kvStorage[size];
    char* endPtr;
    index = 0;
    int k;
    char* v;

    while ((read = getline(&line, &len, data)) != -1)
    {
      line[strcspn(line, "\n")] = 0;
      k = strtol(strsep(&line, ","), &endPtr, 0);
      v = strsep(&line, ",");

      kvStorage[index] = (Keymap*)malloc(sizeof(Keymap*));
      kvStorage[index]->value = v;
      kvStorage[index]->key = k;
      index++;
    }

    if (line)
		  free(line);

    fclose(data);
  }

	for (int i = 1; i < argc; i++){
		command = argv[i];
    count = 0;
    // printf("command is %s, size is %d, num is %d\n", command, size, num);
    for (int j = 0; j < strlen(command); j++){
      if(command[j] == ','){
        count++;
      }
    }
    count++;

    //split command
    char* commandLine[count];
    seperate(command, deli, count, commandLine);


    switch(commandLine[0][0]){
      //put
      case 'p':
        if (count != 3){
          printf("Bad Command!\n");
          break;
        }
        //check if key is int
        if(strspn(commandLine[1], "0123456789") != strlen(commandLine[1])){
          printf("Bad Command!\n");
          break;
        }
        //check if already in database
        exist = 1;
        key = atoi(commandLine[1]);
        for(int j = 0; j < num; j++){
          if(key == kvStorage[j]->key){
            exist = 0;
            index = j;
            break;
          }
        }
        //if in kvStorage
        if(exist){
          //if it is a new key
          kvStorage[num] = (Keymap*)malloc(sizeof(Keymap*));
          kvStorage[num]->key = key;
          kvStorage[num]->value = commandLine[2];
          num++;
        }
        else{
          kvStorage[index]->value = commandLine[2];
        }
        break;

      //get
      case 'g':
        if(count != 2){
          printf("Bad Command!\n");
          break;
        }
        //check whether key is int
        if(strspn(commandLine[1], "0123456789")!=strlen(commandLine[1])){
          printf("Bad Command!\n");
          break;
        }
        key = atoi(commandLine[1]);
        //check whether key has already in the kvStorage
        exist = 1;
        for(int j = 0; j < num; j++){
          if(key == kvStorage[j]->key){
            printf("%d,%s\n", kvStorage[j]->key, kvStorage[j]->value);
            exist = 0;
            break;
          }
        }
        if(exist)
          printf("%d not found!\n", key);
        break;

      //all
      case 'a':
        if(count != 1){
          printf("Bad Command!\n");
          break;
        }
        for(int j = 0; j < num; j++){
          printf("%d,%s\n", kvStorage[j]->key, kvStorage[j]->value);
        }
        break;

      //clear
      case 'c':
        if(count != 1){
          printf("Warning: Bad Command!\n");
          break;
        }
        for(int j = 0; j < num; j++){
          free(kvStorage[j]);
          kvStorage[j] = NULL;
        }
        num = 0;
        break;

      //delete
      case 'd':
        if(count != 2){
          printf("Warning: Bad Command!\n");
          break;
        }
        //check whether key is int
        if(strspn(commandLine[1], "0123456789")!=strlen(commandLine[1])){
          printf("Bad Command!");
          break;
        }
        key = atoi(commandLine[1]);
        //check whether key has already in the kvStorage
        exist = 1;
        for(int j = 0; j < num; j++){
          if(key == kvStorage[j]->key){
            exist = 0;
            index = j;
            break;
          }
        }
        if(exist){
          printf("%d not found!\n", key);
        }
        else{
          num--;
          free(kvStorage[index]);
          kvStorage[index] = NULL;
          for(int j = index; j < num; j++){
            kvStorage[j] = kvStorage[j+1];
          }
        }
        break;

      default:
        printf("Bad Command!\n");
        break;

    }
	}

		FILE *output = fopen("database.txt", "w+");
		fprintf(output, "%d\n", size);
		fprintf(output, "%d\n", num);
		for(int i = 0; i<num; i++){
		// printf("data[%d] is %d, %s\n", i, database[i]->key, database[i]->value);
		fprintf(output, "%d,%s\n", kvStorage[i]->key, kvStorage[i]->value);
		}
		fclose(output);
		return 0;
}
