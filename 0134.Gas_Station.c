#include <stdio.h>

int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
    int total_gas, current_gas;
    int answer;

    total_gas = 0;
    current_gas = 0;
    answer = 0;

    for(int i = 0; i < gasSize; ++i)
    {
        total_gas += gas[i] - cost[i];
        current_gas += gas[i] - cost[i];

        if(current_gas < 0)
        {
            current_gas = 0;
            answer = i + 1;
        }
    }

    if(total_gas >= 0)
        return answer;
    else
        return -1;
}

int main()
{
    int gas[5] = {1, 2, 3, 4, 5};
    int cost[5] = {3, 4, 5, 1, 2};
    int answer;

    answer = canCompleteCircuit(gas, 5, cost, 5);

    printf("answer: %d\n", answer);

    return 0;
}
