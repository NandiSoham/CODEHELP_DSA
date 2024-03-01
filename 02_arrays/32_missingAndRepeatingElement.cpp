#include <iostream>
#include <vector>
using namespace std;

//-------------------------BRUTE FORCE---------------------------------------

// vector<int> findMissingAndRepeatingElementBrute(vector<int> arr)
// {
//     int n = arr.size();
//     int missingElemnt = -1, repeatingElement = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         int count = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j] == i)
//                 count++;
//         }

//         if (count == 2)
//             repeatingElement = i;
//         if (count == 0)
//             missingElemnt = i;

//         if (repeatingElement != -1 && missingElemnt != -1)
//             break;
//     }
//     return {repeatingElement, missingElemnt};
// }

//----------------------------------------------------------------

//--------------------------BETTER APPROACH(Using Hashing)--------------------------------------

vector<int> findMissingRepeatingNumbersBetter(vector<int> arr)
{
    int n = arr.size();
    int missingElemnt = -1, repeatingElement = -1;
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            repeatingElement = i;
        else if (hash[i] == 0)
            missingElemnt = i;

        if (missingElemnt != -1 && repeatingElement != -1)
            break;
    }
    return {repeatingElement, missingElemnt};
}
//----------------------------------------------------------------------------

//---------------------------Optimal Approach-------------------------------------------------

vector<int> findMissingRepeatingNumbersOptimal(vector<int> arr)
{
    long long n = arr.size();

    long long sumN = (n * (n + 1)) / 2;
    long long sqrSumN = (n * (n + 1) * (2 * n + 1)) / 6;

    long long sumArr = 0; 
    long long sqrSumArr = 0;
    for (int i = 0; i < n; i++)
    {
        sumArr += arr[i];
        sqrSumArr += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = sumArr - sumN;
    long long val2 = sqrSumArr - sqrSumN;
    val2 = val2 / val1;

    long long X = (val1 + val2) / 2;
    long long Y = X - val1;

    return{(int)X, (int)Y};
}

//----------------------------------------------------------------

int main()
{
    vector<int> arr = {3, 8, 2, 4, 4, 6, 1, 5};
    // vector<int> ans = findMissingAndRepeatingElementBrute(arr);
    // vector<int> ans2 = findMissingAndRepeatingElementBrute(arr);
    vector<int> ans3 = findMissingRepeatingNumbersOptimal(arr);
    cout << "The repeating and missing elements are: " << ans3[0] << ", " << ans3[1] << endl;
    return 0;
}