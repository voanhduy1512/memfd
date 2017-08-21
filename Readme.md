This is a sample c program to reproduce the problem running [flow]() on
Openshift.

Somehow after `memfd_create`, `ftruncate` throws `EACCES (Permission denied)`
