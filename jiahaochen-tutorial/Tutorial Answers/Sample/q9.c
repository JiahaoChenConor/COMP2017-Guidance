#include "q9.h"

// signal is used for communication between child processes, cleaner and worker
// and pipe is for parent and chilren processes

// In two children processes, use pipe for read (blocked)

// After pop/ push
// In parent process, use pipe to send info to cleaner if stack is full or empty
// In parent process, use pipe to send info to worker if stack is not full or not empty
