
#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <ctype.h>

#define MAXTITL 41

#define MAXAUTL 31

#define MAXBKS 10

 

char * s_gets(char * st, int n);

 

struct book{

    char title[MAXTITL];

    char author[MAXAUTL];

    float value;

    int delete;

};

 

int main(void)

{

    struct book library[MAXBKS] = { {'\0', '\0', 0.0, 0} };

    int count = 0;

    int index, filecount;

    FILE *pbooks;

    int size = sizeof(struct book);

 

    if ((pbooks = fopen("book.dat", "r+b")) == NULL)

    {

        fputs("Can't open book.dat file\n", stderr);

        exit(-1);

    }

 

    rewind(pbooks);  //定位至文件开始处

    while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) //fread返回值为1表示读取成功，不成功则返回0

    {

        if(count == 0)

            puts("current contents of book.dat");

        printf("%s by %s : $%.2f\n",library[count].title, library[count].author, library[count].value); //显示文件信息

        count++;

    }

    filecount = count;  //标记原本文件中所含的结构个数

    if(count == MAXBKS)

    {

        fputs("The book.dat file is full.",stderr);

        exit(2);

    }

 

    puts("Please add new book titles.");

    puts("Press [enter] at the start of a line to stop.");

    while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')

    {

        puts("Now enter the author.");

        s_gets(library[count].author, MAXAUTL);

        puts("Now enter the value.");

        scanf("%f", &library[count++].value);

        while(getchar() != '\n')

            continue;

        if(count < MAXBKS)

            puts("Enter the next title.");

    }

 

    if(count > 0)

    {

        puts("Here is the list of your books : ");

        for(index = 0; index < count; index++)

            printf("%s by %s : $%.2f\n", library[index].title, library[index].author, library[index].value);

        fwrite(&library[filecount], size, count - filecount, pbooks); //已有filecount个文件已存在，则从第filecount+1个文件的地址开始写入，且每个单元大小为size，一共写入count-filecount个单元到pbooks指定的文件中

 

    }

    else

        puts("No books? Too bad.\n");

 

    while(1)

    {

        int choice;

        char ch;

 

        printf("Which book do you want to delete or modify (-1 to quit)?\n");

        scanf("%d", &choice);

        getchar();

        if(choice == -1)

        {

            break;

        }

        printf("[D]elete or [M]odify?\n");

        scanf("%c",&ch);

        getchar();

        ch = toupper(ch);

        if(ch == 'D')

        {

            library[choice-1].delete = 1;

            printf("The information has been deleted.\n");

        }

        if(ch == 'M')

        {

            printf("Please enter the book title.\n");

            s_gets(library[choice-1].title, MAXTITL);

            printf("Now enter the author.\n");

            s_gets(library[choice-1].author, MAXAUTL);

            printf("Now enter the value.\n");

            scanf("%f", &library[choice-1].value);

            while (getchar() != '\n')

            {

                continue;

            }

        }

    }

    fclose(pbooks);

 

    if((pbooks = fopen("book.dat", "w")) == NULL)

    {

        fputs("Can't open the file book.dat\n",stderr);

        exit(-1);

    }

    for(int i = 0; i < count; i++)

    {

        if(library[i].delete != 1)

            fwrite(&library[i], size, 1, pbooks);  //文件清空了，但是数据流还在内存中，可以再向文件中写入

    }

    puts("Done.\n");

    fclose(pbooks);

 

    return 0;

}

 

char * s_gets(char * st, int n)

{

    char * ret_val;

    char * find;

 

    ret_val = fgets(st, n, stdin);

    if(ret_val)

    {

        find = strchr(st, '\n');

        if(find)

            *find = '\0';

        else

            while(getchar() != '\n')

                continue;

    }

    return ret_val;

}
