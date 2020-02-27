# fillit

So far one of the most funniest projects at Hive helsinki! The project was a collaboration project and my teammember for this project was [Petrus Hakakoski](https://github.com/RandommUser).

The problem given for our fillit project was to create a program to assemble a set (maximum 26) of tetris(4 block geometric figure) into the smallest possible square.

Allowed functions were our own libft, exit, open, close, write, read, malloc and free.

The program will take a file as a parameter and the file should contain 1 - 26 tetriminos, each tetrimino separated by a newline. Each tetrimino had to be a 4x4square and each tetris within the tetrimino had to be exactly 4 blocks made of hashes, the rest of the blocks should be dots. 
The program should write the usage or an error in case the file (e.g. no newline between tetriminos) or any of the tetriminos (e.g. tetris with too many blocks) was invalid.

As an example file
```
....
#...
#...
##..

....
##..
##..
....
```

# How to
Compile the executable fillit by running ```make all```.

```
./fillit [file_name]
```
Result
```
ABB
ABB
AA.
```


