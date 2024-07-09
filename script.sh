#!/bin/bash

# Number of repetitions
n=250
# Output file
output_file="output.txt"

# Clear the output file if it exists
> $output_file

# Loop n times
for ((i=1; i<=n; i++))
do
  # Run the commands and store the result
  ARGS=$(./a.out 100)
  result=$(./push_swap $ARGS | wc -l)
  
  # Write the result to the output file
  echo "Run #$i: $result" >> $output_file
done

echo "Results written to $output_file"

