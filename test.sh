output=$(./bin/02_odd_even 1)
expectation="ODD"
if [ "$output" == "$expectation" ]; then
    echo "Test passed"
else
    echo "Test failed"
fi

output=$(./bin/02_odd_even 2)
expectation="EVEN"
if [ "$output" == "$expectation" ]; then
    echo "Test passed"
else
    echo "Test failed"
fi

output=$(./bin/02_odd_even)
expectation="No program arguments found."
if [ "$output" == "$expectation" ]; then
    echo "Test passed"
else
    echo "Test failed"
fi