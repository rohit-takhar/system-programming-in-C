#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	struct stat buff;
	int usr=0,grp=0,oth=0,reg=0,dir=0;
	if(argc > 2)
	{	printf("Too many arguments\n");
		exit(0);
	}
	else
	if(argc < 2)
	{
		printf("Few arguments\n");
                exit(0);	
	}
	stat(argv[1],&buff);
	
	if(buff.st_mode & S_IFREG)
	{
		reg=1;
	}
	
	if(buff.st_mode & S_IFDIR)
        {
                dir=1;
        }

	

	if(buff.st_mode & S_IRUSR)
	{
		usr+=4;
	}
	if(buff.st_mode & S_IWUSR)
	{
		usr+=2;
	}
	if(buff.st_mode & S_IXUSR)
	{
		usr+=1;
	}
	
	if(buff.st_mode & S_IRGRP)
        {
                grp+=4;
        }
        if(buff.st_mode & S_IWGRP)
        {
                grp+=2;
        }
        if(buff.st_mode & S_IXGRP)
        {
                grp+=1;
        }
	

	if(buff.st_mode & S_IROTH)
        {
                oth+=4;
        }
        if(buff.st_mode & S_IWOTH)
        {
                oth+=2;
        }
        if(buff.st_mode & S_IXOTH)
        {
                oth+=1;
        }
	if(reg==1)
	{
		printf("File is a regular file\n");
		printf("No. of links: %d\n",buff.st_nlink);
		printf("User ID: %d\n",buff.st_uid);
		printf("Group ID: %d\n",buff.st_gid);
		printf("File size: %lld bytes\n",(long)buff.st_size);
		printf("File permissions: %d%d%d\n",usr,grp,oth);	
	}
	else
	if(dir == 1)
	{
		printf("Directory details\n");
		printf("No. of links: %d\n",buff.st_nlink);
		printf("User ID: %d\n",buff.st_uid);
		printf("Group ID: %d\n",buff.st_gid);
		printf("File size: %lld bytes\n",(long)buff.st_size);
		printf("Permissions: %d%d%d\n",usr,grp,oth);	
	
	}	
return 0;
}
