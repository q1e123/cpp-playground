output=$(./bin/01_hello_world )
expectation="Hello from [Robert-Nicolae Solca]"
if [ "$output" == "$expectation" ]; then
    echo "Test passed"
else
    echo "Test failed"
fi