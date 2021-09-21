/*
 * kv.c
 *
 *  Created on: 2021��9��18��
 *      Author: 87179
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct  {
	int key;
	char *value;
} kv;

typedef struct  {
    kv kvStorage[2000];
    int current;
} Map;


void *put(int *key, char* value, Map map){
	/*
	 * 	if(map.current == map.size-1){
		struct kv *newStorage[map.size*2];
		newStorage = malloc(sizeof(*newStorage));

		for(int i = 0; i<map.size; i++){
			newStorage[i] = map.kvStorage[i];
		}

		memcpy(map->kvStorage, newStorage, sizeof(*newStorage));
		map.size = map.size*2;
	}
	 */

	kv newElement = newElement;
	newElement.key = *key;
	newElement.value = value;
	map.kvStorage[map.current] = newElement;
	map.current++;

	//printf("%d",1);




}

char *get(int *tokenKey, Map map){

	for(int i = 0; i<=map.current; i++){
		if(map.kvStorage[i].key == *tokenKey){
			kv res;
			//memcpy(res, map.kvStorage[i], sizeof(map.kvStorage[i]));
			//res = *map.kvStorage[i];
			//printf("%d", *res.key);
			printf("%s", ",");
			//printf("%s\n", res.value);
		}else{
			printf("%d", *tokenKey);
			printf("%s", " not found");
		}
	}

}

void delete(int key){

}

void clear(){

}

void all(){

}

void main(int argc, char** argv){

	if (argc == 1){
		printf("Command line should start with p, g, a, c, d.\n");
		exit(1);
	}

	Map map = map;
	map.current = 0;

	for(int i = 1; i<argc; i++){
		char * token = strtok(argv[i], ", ");
			   // loop through the string to extract all other tokens
				int j = 0;
			   while( j == 0 ) {
				   j++;
			      //printf( " %s\n", token ); //printing each token
			      if(strcmp(token, "p")!= 0 && strcmp(token, "g")!= 0 && strcmp(token, "a")!= 0 && strcmp(token, "c")!= 0 && strcmp(token, "d")!= 0){
			    	  printf("%s", "bad command");
			    	  continue;
			      }
			      if(*token == 'p'){
			    	  token = strtok(NULL, " ");
			    	  int tokenKey = atoi(token);
                      // printf("\n%d", tokenKey);
			    	  // sscanf(token, "%d", tokenKey);
			    	  token = strtok(NULL, " ");
			    	  put(&tokenKey, token, map);
			    	  //printf("%s", "p is fine");
			      }else if(*token == 'g'){
			    	  token = strtok(NULL, " ");
			    	  int tokenKey = atoi(token);
			    	  //printf("%s", "g is fine");
			    	  get(&tokenKey, map);
			      }
			   }
	}






	/*
	 * 	struct Map map = map;
	map.size = 20;
	map.current = 19;

	put(4, "2",map);

	printf("%s\n", argv[0]);
	printf("%s", argv[1]);
	// printf("%i", argc);

	char * token = strtok(argv[1], ", ");
	   // loop through the string to extract all other tokens
	   while( token != NULL ) {
	      printf( " %s\n", token ); //printing each token
	      token = strtok(NULL, " ");
	   }
	 */
}


