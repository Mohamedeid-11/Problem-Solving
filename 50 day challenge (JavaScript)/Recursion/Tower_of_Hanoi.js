/*
cd "50 day challenge\Recursion"
node Tower_of_Hanoi.js
*/

function helper(N, from, to, aux) 
{
    if(N === 0) return 0;

    helper(N-1, from, aux, to);
    console.log("move disk " + N + " from rod " + from + " to rod " + to);
    helper(N-1, aux, to, from);
}

function toh(N, from, to, aux)
{
    helper(N, from, to, aux);
    return Math.pow(2,N) - 1;
}


console.log(toh(2, 1, 3, 2));
