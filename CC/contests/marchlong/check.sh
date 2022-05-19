
for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > in1
    ./sol < in1 > out1
    ./brute < in1 > out
    diff -w out1 out || break
    # diff -w <(./a < int) <(./brute < int) || break
done