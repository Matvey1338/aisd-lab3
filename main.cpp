#include "sorting.h"

using namespace std;

int main()
{
    std::srand(std::time(nullptr));

    std::vector<size_t> sizes = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };
    const size_t max_num = 100;
    /*
    std::ofstream file("C:/Users/matve/OneDrive/Рабочий стол/project_current_semestr/aisd/lab3/sort_results/bubble_sort_results.csv");
    file << "Size,Avg Comparisons,Avg Copies,Sorted Comparisons,Sorted Copies,Reverse Comparisons,Reverse Copies\n";
    std::cout << "BUBBLE:" << "\n";
    std::cout << "----------------------------------" << std::endl;

 
    for (size_t size : sizes)
    {
        long long total_comparisons = 0;
        long long total_copies = 0;

        for (size_t i = 0; i < max_num; ++i)
        {
            std::vector<int> arr(size);
            generator(arr, size, i);

            stats result = BublleSort(arr);

            total_comparisons += result.comparison_count;
            total_copies += result.copy_count;
        }

        long long avg_comparisons = total_comparisons / max_num;
        long long avg_copies = total_copies / max_num;

        std::cout << "Size: " << size << std::endl;
        std::cout << "Average comparisons: " << avg_comparisons << std::endl;
        std::cout << "Average copies: " << avg_copies << std::endl;

        std::vector<int> sorted_arr(size);
        generateSortedArray(sorted_arr, size);
        stats sorted_result = BublleSort(sorted_arr);
        std::cout << "Comparisons (sorted): " << sorted_result.comparison_count << std::endl;
        std::cout << "Copies (sorted): " << sorted_result.copy_count << std::endl;

        std::vector<int> reverse_sorted_arr(size);
        generateReverseSortedArray(reverse_sorted_arr, size);
        stats reverse_sorted_result = BublleSort(reverse_sorted_arr);
        std::cout << "Comparisons (reverse sorted): " << reverse_sorted_result.comparison_count << std::endl;
        std::cout << "Copies (reverse sorted): " << reverse_sorted_result.copy_count << std::endl;

        std::cout << "----------------------------------" << std::endl;

        file << size << ","
            << avg_comparisons << ","
            << avg_copies << ","
            << sorted_result.comparison_count << ","
            << sorted_result.copy_count << ","
            << reverse_sorted_result.comparison_count << ","
            << reverse_sorted_result.copy_count << "\n";
    }
    file.close();
    std::cout << "Results saved to bubble_sort_results.csv" << std::endl;
    */

    /*
    std::ofstream file("C:/Users/matve/OneDrive/Рабочий стол/project_current_semestr/aisd/lab3/sort_results/comb_sort_results.csv");
    file << "Size,Avg Comparisons,Avg Copies,Sorted Comparisons,Sorted Copies,Reverse Comparisons,Reverse Copies\n";

    std::cout << "COMB:" << "\n";
    std::cout << "----------------------------------" << std::endl;


    for (size_t size : sizes)
    {
        long long total_comparisons = 0;
        long long total_copies = 0;

        for (size_t i = 0; i < max_num; ++i)
        {
            std::vector<int> arr(size);
            generator(arr, size, i);

            stats result = CombSort(arr);

            total_comparisons += result.comparison_count;
            total_copies += result.copy_count;
        }

        long long avg_comparisons = total_comparisons / max_num;
        long long avg_copies = total_copies / max_num;

        std::cout << "Size: " << size << std::endl;
        std::cout << "Average comparisons: " << avg_comparisons << std::endl;
        std::cout << "Average copies: " << avg_copies << std::endl;

        std::vector<int> sorted_arr(size);
        generateSortedArray(sorted_arr, size);
        stats sorted_result = CombSort(sorted_arr);
        std::cout << "Comparisons (sorted): " << sorted_result.comparison_count << std::endl;
        std::cout << "Copies (sorted): " << sorted_result.copy_count << std::endl;

        std::vector<int> reverse_sorted_arr(size);
        generateReverseSortedArray(reverse_sorted_arr, size);
        stats reverse_sorted_result = CombSort(reverse_sorted_arr);
        std::cout << "Comparisons (reverse sorted): " << reverse_sorted_result.comparison_count << std::endl;
        std::cout << "Copies (reverse sorted): " << reverse_sorted_result.copy_count << std::endl;

        std::cout << "----------------------------------" << std::endl;

        file << size << ","
            << avg_comparisons << ","
            << avg_copies << ","
            << sorted_result.comparison_count << ","
            << sorted_result.copy_count << ","
            << reverse_sorted_result.comparison_count << ","
            << reverse_sorted_result.copy_count << "\n";
    }
    file.close();
    std::cout << "Results saved to comb_sort_results.csv" << std::endl;
    */

    std::ofstream file("C:/Users/matve/OneDrive/Рабочий стол/project_current_semestr/aisd/lab3/sort_results/pyramid_sort_results.csv");
    file << "Size,Avg Comparisons,Avg Copies,Sorted Comparisons,Sorted Copies,Reverse Comparisons,Reverse Copies\n";

    std::cout << "PYRAMID:" << "\n";
    std::cout << "----------------------------------" << std::endl;


    for (size_t size : sizes)
    {
        long long total_comparisons = 0;
        long long total_copies = 0;

        for (size_t i = 0; i < max_num; ++i)
        {
            std::vector<int> arr(size);
            generator(arr, size, i);

            stats result = heapSort(arr);

            total_comparisons += result.comparison_count;
            total_copies += result.copy_count;
        }

        long long avg_comparisons = total_comparisons / max_num;
        long long avg_copies = total_copies / max_num;

        std::cout << "Size: " << size << std::endl;
        std::cout << "Average comparisons: " << avg_comparisons << std::endl;
        std::cout << "Average copies: " << avg_copies << std::endl;

        std::vector<int> sorted_arr(size);
        generateSortedArray(sorted_arr, size);
        stats sorted_result = heapSort(sorted_arr);
        std::cout << "Comparisons (sorted): " << sorted_result.comparison_count << std::endl;
        std::cout << "Copies (sorted): " << sorted_result.copy_count << std::endl;

        std::vector<int> reverse_sorted_arr(size);
        generateReverseSortedArray(reverse_sorted_arr, size);
        stats reverse_sorted_result = heapSort(reverse_sorted_arr);
        std::cout << "Comparisons (reverse sorted): " << reverse_sorted_result.comparison_count << std::endl;
        std::cout << "Copies (reverse sorted): " << reverse_sorted_result.copy_count << std::endl;

        std::cout << "----------------------------------" << std::endl;

        file << size << ","
            << avg_comparisons << ","
            << avg_copies << ","
            << sorted_result.comparison_count << ","
            << sorted_result.copy_count << ","
            << reverse_sorted_result.comparison_count << ","
            << reverse_sorted_result.copy_count << "\n";
    }
    file.close();
    std::cout << "Results saved to pyramid_sort_results.csv" << std::endl;

	return 0;
}
