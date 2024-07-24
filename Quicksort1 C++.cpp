#include<iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    //this function place the start element in its correct position and returns this position value

    //First step is to find the correct position of the start element

    //finding all the elements which are less than the partition element

    int i, number_lessthan_part;
    for(i=start+1,number_lessthan_part=0;i<end+1;i++)
    {
        if(arr[i]<arr[start])
        {
            //This means that this element will be to the left of the partition element

            number_lessthan_part++;
        }
    }

    //now the actual index will just be :
    int correct_index;

    correct_index = start + number_lessthan_part;

    //I will simply swap the start element and the correct index element

    int temp;
    temp = arr[start];
    arr[start] = arr[correct_index];
    arr[correct_index] = temp;

    //Now after we have placed this element in its correct position, we need to make sure that this is actually at its actual position

    //Making sure that this element is at its correct position :

    int j;
    i = start;
    j = end;
    while(i<correct_index && j>correct_index)
    {
        while(arr[i] < arr[correct_index])
        {
            //This while loop will keep on transversing until we find an element to the right of correct index which is greater than correct index
            i++;
        }
        while(arr[j] > arr[correct_index])
        {
            //This loop will break when we find an element which is less than correct index
            j--;
        }

        if(i<correct_index && j>correct_index)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }
    return correct_index;
}
void quickSort(int *arr, int start, int end)
{
    if(start>=end)
    {
        return;
    }
    //partition is the element which is at its "correct place " --> its position doesn't change even after we sort the numbers
    //First step is to find a partition such that its

    int partition_index;
    partition_index = partition(arr, start, end);

    //this function will return the actual position of the start element

    //since after running the function, I know that the start element is placed in its "correct" positon and we know that position through position_index, we don't need to change the position of partition_index anymore

    quickSort(arr,start,partition_index-1);
    quickSort(arr,partition_index+1,end);
    

}
int main()
{
    int size;
    int arr[7] = {5,1,3,10,7,14,2};

    size = 7;

    quickSort(arr,0,size-1);

    int k;

    for(k=0;k<size;k++)
    {
        cout<<arr[k]<<" ";
    }
    return 0;
}
