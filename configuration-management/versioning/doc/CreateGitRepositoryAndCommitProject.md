# Example: Create Local Git Repository and Commit a Simple C Project

In this example we create a local Git repository and save a C 
project in it.

## Create a simple C project

```
$ mkdir -p sandbox/c-example
$ cd sandbox/c-examples
```

First, we implement a simple C file called "complex_numbers.c":
```
$ vi complex_numbers.c
```

```C
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct complex_number
{
    double re;
    double im;
} complex;

complex complex_add(complex a, complex b)
{
	complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

int main(void)
{
    complex c1 = {1.0, 1.0};
    complex c2;
    c2.re = 2.0;
    c2.im = 4.0;

    printf("c1 = (%f,%f)\n", c1.re, c1.im);
    printf("c2 = (%f,%f)\n", c2.re, c2.im);
    
    complex result = complex_add(c1,c2);
    printf("c1 + c2 = (%f,%f)\n", result.re, result.im);

    complex *c_ptr;
    c_ptr = (complex*)malloc(sizeof(complex)); 
    c_ptr->re = 7.0;
    c_ptr->im = -13.0;
    printf("*c_ptr = (%f,%f)\n", c_ptr->re, c_ptr->im);    
    free(c_ptr);
    
    return 0;
}    
```

We compile the C file into an execuable:
```
$ gcc -Wall -o complex_numbers complex_numbers.c

$ tree
.
├── complex_numbers
└── complex_numbers.c
```

To execute the binary we type:
```
$ ./complex_numbers 
c1 = (1.000000,1.000000)
c2 = (2.000000,4.000000)
c1 + c2 = (3.000000,5.000000)
*c_ptr = (7.000000,-13.000000)
```

Well done. Now we have a very simple C project which we can put into a
Git repository.


## Create a Git repository

We create the Git repository within our C project directory: 
```
$ pwd
sandbox/c-examples

$ git init
Initialized empty Git repository in sandbox/c-example/.git/

$ ll -a
drwxr-xr-x 3 pi pi  4096 Feb 24 20:00 .
drwxr-xr-x 5 pi pi  4096 Feb 24 19:58 ..
-rwxr-xr-x 1 pi pi 15592 Feb 24 19:59 complex_numbers
-rw-r--r-- 1 pi pi   755 Feb 24 19:42 complex_numbers.c
drwxr-xr-x 7 pi pi  4096 Feb 24 20:00 .git

$ git status
Auf Branch master

Noch keine Commits

Unversionierte Dateien:
  (benutzen Sie "git add <Datei>...", um die Änderungen zum Commit vorzumerken)

	complex_numbers
	complex_numbers.c

nichts zum Commit vorgemerkt, aber es gibt unversionierte Dateien
(benutzen Sie "git add" zum Versionieren)
```
	
## Commit the C project files to the repository

We have to tell Git which files should not be managed by providing a
**.gitignore** file:
```
$ vi .gitignore
# Files ignored by Git:
/complex_numbers
```


```
$ git add .gitignore 
$ git add complex_numbers.c 

$ git status
Auf Branch master
Noch keine Commits
Zum Commit vorgemerkte Änderungen:
  (benutzen Sie "git rm --cached <Datei>..." zum Entfernen aus der Staging-Area)

	neue Datei:     .gitignore
	neue Datei:     complex_numbers.c
```


Finally, we commit all files which are in the staging area:
```
$ git commit -m "Initial import."
[master (Basis-Commit) bdbd20e] Initial import.
 2 files changed, 42 insertions(+)
 create mode 100644 .gitignore
 create mode 100644 complex_numbers.c

$ git status
Auf Branch master
nichts zu committen, Arbeitsverzeichnis unverändert
```

## References
* [Pro Git Book](https://git-scm.com/book/en/v2)

*Egon Teiniker, 2020, GPL v3.0*
