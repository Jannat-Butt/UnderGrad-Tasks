
//Q1
void swap(int* iptra, int* iptrb)
{
	//i_temp variable will hold the value of pointer a(first value)
	int i_temp = *iptra;
	*iptra = *iptrb;
	*iptrb = i_temp;
}

//Q2
int difference(int* iarray_address, int isize)
{
    int diff_of_max_and_min = 0;
    int max_value = 0, min_value = 0;
    //This for loop will execute till size of array

    for (int index = 0; index < isize; index++) //This loop will find minimum value in array
    {
        //with the increment of index, pointer will move to next location in memory as (iarray_address+i)
        //if first(starting element) is greater than the element at next loaction
        //than second element will be moved at the location of first element
        if (*(iarray_address) > *(iarray_address + index))
        {
            *(iarray_address) = *(iarray_address + index);
        }
    }
    //now starting value is the minimum value that pointer points to
    min_value = *(iarray_address);
    for (int i = 0; i < isize; i++)//this loop will find max value
    {
        //if first(starting element) is smaller than the element at next loaction
        //than second element will be moved at the location of first element
        if (*(iarray_address) < *(iarray_address + i))
        {
            *(iarray_address) = *(iarray_address + i);
        }
    }
    //now starting value is the max value that pointer points to.
    max_value = *(iarray_address);
    //this will calculate difference of max and min value
    diff_of_max_and_min = max_value - min_value;
    return diff_of_max_and_min;
    //de-allocate the heap
    delete[]iarray_address;
    iarray_address = nullptr;
}

//Q3
int if_exists(char* chPointer, char character_to_find)
{
	//loop will execute 10 times till the size of array

	for (int index = 0; index < 10; index++)
	{
		//with the increment of index, character Pointer 
		//will move forward to the next location
		if (*(chPointer + index) == character_to_find)
		{
			//if character if found at any location of array than 
			//it will return true
			return 1;
		}
	}
	//else false
	return 0;
    //de-allocating the heap
    delete[]chPointer;
    chPointer = nullptr;
}

//Q4
int* merge(int* array1, int* array2)
{
    int* arr3 = new int[13];//dynamically allocated
    //first 9 locations of arr3 will be filled
    //occourding to the given instruction as in question,
    //to fill arr3 by comparing the indexes of arr1 and arr2
    //the smaller element will be inserted in arr3 first
    for (int index = 0; index < 10; index++)
    {
        if (*(array1) < *(array2))
        {
            *(arr3 + index) = *(array1);
            //as if arr1 element is smaller 
            //than arr1 pointer will pointer
            //to its next value
            array1 = array1 + 1;
        }
        else
        {
            //if arr1 element is not smaller
            //forsure element of arr2 will be smaller
            *(arr3 + index) = *(array2);
            //after assigning the element to array3
            //array2 will point to its next location
            array2 = array2 + 1;
        }

    }
    for (int remainingIndex = 10; remainingIndex < 13; remainingIndex++)
    {
        //as the remaining elements left 
        //in array2 will not be compared
        //as they are only elements
        //so they are directly copied to array3
        *(arr3 + remainingIndex) = *(array2);
        //array2 will point to its next location
        array2++;
    }
    return arr3;
    //de-allocation
    delete[]arr3;
    arr3 = nullptr;
    //de-allocation
    delete[]array1;
    array1 = nullptr;
    delete[]array2;
    array2 = nullptr;
}

//Q5
int * hist(float * arr1, int size)
{
    //dynamic allocation of array frequency
    int * Freq = new int[size];
    //For loop to sort array in descending order 
    //so that we can have elements accourding to their 
    //order.
    for (int indexI = 0; indexI < size; indexI++)
    {
        //indexI will will start from initial value and 
        //check itself from the value at next index
        for (int indexJ = indexI + 1; indexJ < size; indexJ++)
        {
            //indexJ is showing the element which is next to element of indexI
            //This loop will check the element of indexI in whole array
            if (*(arr1 + indexI) < *(arr1 + indexJ))
            {
                //temp is temporary var to hold value
                float temp = *(arr1 + indexJ);
                *(arr1 + indexJ) = *(arr1 + indexI);
                *(arr1 + indexI) = temp;
            }

        }
        //at this point index of I(indexI) will change and it will 
        //now move to next location in array
    }

//Here the Frequency will be counted
      int i = 0;
      //i is indexes of our Freq array
      //we only want to store the non-zero counts 
      //so we will make the size of freq by our self

    for (int indexI = 0; indexI < size; indexI++)
    {
        //repetition will see if the same element is counted before previously
        //it will not let to count that again
        int repetition = 0;
        //freqcounter will count the similar elements
        //when no repetition is found
        int freqCounter = 1;  
        for (int Rindex = 0; Rindex < indexI; Rindex++)
        {
            //as Rindex(repetition index) it will check the
            //current element on previous array locations [  <-  7]
            //to see if this element was already counted or not
            if (*(arr1 + indexI) == *(arr1 + Rindex))
            {
                //when repetition is greater than 0 
                //its mean that the element on the 
                //left of array is already counted
                repetition = repetition + 1;
            }
        }
        if (repetition == 0)
        {
            //when no duplicate element is found(backward)than the 
            //loop will move in forward direction and find the same
            //element.
            for (int indexToright = indexI + 1; indexToright < size; indexToright++)
            {
                if (*(arr1 + indexI) == *(arr1 + indexToright))
                {
                    //if the element is found at other(forward)locations
                    //counter will be incremented
                    freqCounter++;

                }
            }
            //after checking similar elements through whole array
            //counter will be assigned to the array of Freq
            *(Freq + i) = freqCounter;
            //i is incremented because now new non-zero
            //frequency will be stored on next index
            i++;
        }
    }
    return Freq;
    //de-ellocate the heap
    delete[]Freq;
    Freq = NULL;
    delete[]arr1;
    arr1 = nullptr;
}

//Q8
int* MergeArrayRecursively(int* array1, int sizeN, int* array2, int sizeM, int* array3, int indexA1, int indexA2, int indexA3)
{
         //if condition keeps on executing till the size of array1 and 
        //array2 is greater than the index of both the arrays
    if (indexA1 < sizeN && indexA2 < sizeM)
    {
        //if value at array1 is smaller than value of array2..
        if (*(array1) < *(array2))
        {
            //than smaller value will be stored in array3 
            *(array3) = *array1;
            //as array1 value is assigned to array3
            //so the pointer(array1) must move to next
            //location(pointing to next value)
            array1 = array1 + 1;
            //Also the index of array1 will increase 
            indexA1++;
        }
        else
        {
            //if array1 value is not smaller, than its mean value at array2 is smaller
            *(array3) = *array2;
            //so value of array2 is assigned to array3
            //in this case pointer(array2) must point to next value, so increment,the address
            array2++;
            //also the index of array2 will move accourdingly
            indexA2++;
        }
        //in recursive call we will move only the pointer(array3) to next loaction(the empty one)
        //also the index of array3 is incremented
        MergeArrayRecursively(array1, sizeN, array2, sizeM, array3 + 1, indexA1, indexA2, indexA3 + 1);
    }
    //this will only execute when some values in either array 1 or array2 will left
    else
    {
        if (indexA2 < sizeM)//at each call checks if the indexof A2 is smaller than size of array2
        {
            //in case if the index of array2 is still smaller than the size of array2
            //ths means that there are some values left in array2
            //that will be directly inserted in array3,one by one as they are already sorted
            *(array3) = *(array2);
            indexA2 = indexA2 + 1;
            array3++;
            array2++;
            //function is called again,that will again check if the index is still smaller than size
            MergeArrayRecursively(array1, sizeN, array2, sizeM, array3, indexA1, indexA2, indexA3 + 1);
        }

        //in case if the index of array1 is still smaller than the size of array1
        //ths means that there are some values left in array1
        //that will be directly inserted in array3, as they are already sorted
        else if (indexA1 < sizeN)
        {
            *(array3) = *(array1);
            indexA1 = indexA1 + 1;
            //array3 will move to next memory address
            array3++;
            //array1 will point to next value
            array1++;
            //again function is called
            MergeArrayRecursively(array1, sizeN, array2, sizeM, array3, indexA1, indexA2, indexA3 + 1);
        }

    }
    //address of array3 (the sorted array) will be returned
    return array3;
}
