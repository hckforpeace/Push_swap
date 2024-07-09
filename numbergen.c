/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbergen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:43:28 by pierre            #+#    #+#             */
/*   Updated: 2024/07/07 08:15:36 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

// Function to check if a number exists in the array
int existsInArray(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1; // Number exists in the array
        }
    }
    return 0; // Number does not exist in the array
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        srand(time(0)); // Seed the random number generator only once
        int iterations = atoi(argv[1]);
        
        if (iterations <= 0) {
            printf("Number of iterations must be positive.\n");
            return 1;
        }

        int *randomNumbers = malloc(iterations * sizeof(int));
        if (!randomNumbers) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        int count = 0;
		printf(" ");
        while (count < iterations)
        {
            int r = rand() % 10000; // Generate a random number between 0 and 1999
            if (!existsInArray(randomNumbers, count, r)) {
                randomNumbers[count] = r;
                printf("%d", r);
                count++;
                if (count < iterations) {
                    printf(" ");
                }
            }
        }
        printf("\n");
        free(randomNumbers); // Free allocated memory
    }
    else
    {
        printf("Usage: %s <number_of_random_numbers>\n", argv[0]);
    }
    return 0;
}
