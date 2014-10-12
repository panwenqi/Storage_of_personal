#include <iostream>
#include <assert.h>
using namespace std;

char* my_strstr(char* string, char* strsubstring);

int main()
{
	char* str1 = "abcbdferdf";
	char* str2 = "bd";
	cout << my_strstr(str1, str2) << endl;

	system("pause");
	return 0;
}

 char *my_strstr(char *s1, char *s2)
  {
    char *temp_s1 = s1, *temp_s2 = s2;
    int i = 0;
    
    assert(s1 != NULL && s2 != NULL);

    if (strlen(s1) < strlen(s2))	
    {
	return NULL;
    }
	if (strlen(s2) == 1)
	{
		while (*temp_s1 != '\0')
		{
			if (*temp_s1++ == *s2)
			{
				return temp_s1 -1;
			}
		}
	}
	temp_s1 = s1;
    while (*temp_s1 != '\0')
    {
        while (*temp_s1++ == *temp_s2++)
        {
            i++;
        }
        
        if (*temp_s2 == '\0')
        {
            return (temp_s1-i-1);
        }
        else
        {
//            temp_s1 = ++temp_s1;
			
            temp_s2 = s2;
            i = 0;
        }
    }

    return NULL;
}