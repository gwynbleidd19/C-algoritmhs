#include <stdint.h>
#include <stdio.h>

int get_value(const char *resp, const char *key, const char **val){
  while (*resp != '\0'){
   if (*resp == *key){
    const char *temp_resp = resp;
    const char *temp_key = key;
    while (*temp_key != '\0' && *temp_key == *temp_resp){
      temp_key++;
      temp_resp++;
    }
    if (*temp_key == '\0'){
      temp_resp++;
      *val = temp_resp;
      return 1;
    }
   }
   resp++;
  }

return 0;
}
int main(void){

  const char *response = "status=ok;temp=25.5;hum=60";
  const char *val = NULL;
 

  if (get_value(response, "penis", &val)){
    printf("Temperature is: %s\n", val);
  } else {
    printf("hasn't been found");
  }

}

