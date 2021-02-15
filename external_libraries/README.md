# External Libraries



```sh

gcc -o ttile.o -c ttile.c
gcc -shared -o libttile.so ttile.o -lm
sudo mv libttile.so /usr/lib/

```