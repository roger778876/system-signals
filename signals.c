#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    int fd;
    fd = open("sigint", O_WRONLY | O_CREAT | O_APPEND, 0644);
    char output[] = "Program exited due to SIGINT";
    write(fd, output, sizeof(output));
    close(fd);
    exit(0);
  }
  else if (signo == SIGUSR1) {
    printf("Parent PID: %d\n", getppid());
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while (1) {
    printf("PID: %d\n", getpid());
    sleep(1);
  }
}