SHELL-in-C:
===========

All basic CLI commands work
---------------------------

Extra commands:
---------------

1. nigtswatch -n <time-in-secs> <dirty,interrupt> : Shows dirty memory or interrupts of CPU according to chosen option after every <time-in-secs>

2. jobs : prints a list of all currently running jobs along with their pid, in particular, background jobs, in order of their creation along with their state – Running or Stopped.

3. kjob <jobNumber> <signalNumber> : takes the job id of a running job and sends a signal value to that process

4. fg <jobNumber> : brings a running or a stopped background job with given job number to foreground.

5. bg <jobNumber> : changes a stopped background job to a running background job.

6. bg <jobNumber> : changes a stopped background job to a running background job.

7. setenv var [value] : If environment variable var does not exist, then your shell must create it. Your shell must set the value of var to value, or to the empty string if value is omitted. Initially, your shell inherits environment variables from its parent. Your shell must be able to modify the value of an existing environment variable or create a new environment variable via the setenv command. Your shell must be able to set the value of any environment variable; It is an error for a setenv command to have zero or more than two command-line arguments.

8. unsetenv var : Your shell must destroy the environment variable var. It is an error for an unsetv command to have zero command-line arguments.

HOW TO RUN:
===========

> Just type make.
> Run ./SHELL


NOTE:
-----

> q followed by <enter> ends nightswatch
> quit in CLI quits the shell
