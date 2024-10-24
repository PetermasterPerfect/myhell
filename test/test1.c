#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char *arg[] = {"ls", "-la", 0};
	execve("ls", arg, 0);
}
