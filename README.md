clone this code as 

$ git clone https://github.com/lynxbee/json-parsing.git

$ cd json-parsing

Compiling the library:
	
$ make

cc -c  jsmn.c -o jsmn.o
ar rc libjsmn.a jsmn.o

$ git status
On branch master
Untracked files:
  (use "git add <file>..." to include in what will be committed)

	jsmn.o
	libjsmn.a

nothing added to commit but untracked files present (use "git add" to track)

Above "git status" command shows it compiled the libary and created archive

Now, we can compile and run the simple example as, [ You can check Makefile ]
$ make simple_example

cc -c  example/simple.c -o example/simple.o
cc  example/simple.o libjsmn.a -o simple_example

$ ./simple_example 
- User: johndoe
- Admin: false
- UID: 1000
- Groups:
  * users
  * wheel
  * audio
  * video

