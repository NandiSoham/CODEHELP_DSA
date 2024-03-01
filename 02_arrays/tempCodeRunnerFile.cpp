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