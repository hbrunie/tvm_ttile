# External Libraries


## To create the library

```sh

gcc -o ttile.o -c ttile.c
gcc -shared -o libttile.so ttile.o -lm
sudo mv libttile.so /usr/lib/

```

## To test the library

```sh

cd tests
python3 mylib.py

```