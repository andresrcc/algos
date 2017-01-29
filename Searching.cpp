bool BinarySearch(vector<int> numbers, int number_to_find){
    int middle_value, low_bound = 0, high_bound = numbers.size()-1;
    
    if (numbers.empty()) return false;
    
    while(low_bound <= high_bound){
        middle_value = (low_bound + high_bound) / 2; 
        
        if(number_to_find < numbers[middle_value]) high_bound = middle_value - 1;
        else if (number_to_find > numbers[middle_value]) low_bound = middle_value + 1;
        else return true;
    }
    
    return false;
}

bool BinarySearchRecursive(vector<int> numbers, int number_to_find, int low_bound, int high_bound){
    int middle_index = (low_bound + high_bound) / 2;
    
    if(low_bound > high_bound) return false;
    
    if(number_to_find < numbers[middle_index]) BinarySearchRecursive(numbers, number_to_find, low_bound, middle_index - 1);
    else if (number_to_find > numbers[middle_index]) BinarySearchRecursive(numbers, number_to_find, middle_index + 1, high_bound);
    else return true;
}
