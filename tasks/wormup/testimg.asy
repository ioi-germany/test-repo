int N = stdin;

for(int i = 0; i <= 5; ++i)
{
    draw((0,-i*1cm)--(5cm, -i*1cm), .5white);
    draw((i*1cm,0)--(i*1cm,-5cm), .5white);
}

for(int i = 0; i < N; ++i)
{
    int x = stdin, y = stdin;
    fill(shift(x*1cm-.5cm,-y*1cm+.5cm)*scale(.4cm)*unitcircle);
}
