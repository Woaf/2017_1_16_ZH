#include <iostream>

using namespace std;

struct worker
{
    int day_start;
    int day_end;
    int salary;
};

// 1. összegzés tétel
int calculate_total_wage(worker workers[], int size);

// 2. maximumkeresés tétel
int calculate_days_worked_of_max_salary(worker workers[], int size);

// 3. feltételes max keresés és összegzés
int calculate_max_numer_of_workers_on_the_same_day(worker workers[], int size);

// 4. max keresés
int calculate_max_interval(worker workers[], int size);

// 5. keresés tétel
//bool empty_days(worker workers[], int size);
void empty_days(worker workers[], int size);

int main()
{

    int number_of_workers;
    // cin >> number_of_workers;
    number_of_workers = 5;

    worker workers[number_of_workers];

    /*
    for(int i = 0; i < number_of_workers; i++)
    {
        cin >> workers[i].day_start >> workers[i].day_end >> workers[i].salary;
    }
    */
    // test data
    workers[0].day_start = 14; workers[0].day_end = 15; workers[0].salary = 100;
    workers[1].day_start = 1;  workers[1].day_end = 5;  workers[1].salary = 1000;
    workers[2].day_start = 3;  workers[2].day_end = 6;  workers[2].salary = 100;
    workers[3].day_start = 2;  workers[3].day_end = 4;  workers[3].salary = 500;
    workers[4].day_start = 10; workers[4].day_end = 12; workers[4].salary = 100;


    cout << "#" << endl << calculate_total_wage(workers, number_of_workers) << endl << "#" << endl;
    cout << calculate_days_worked_of_max_salary(workers, number_of_workers) << endl << "#" << endl;
    cout << calculate_max_numer_of_workers_on_the_same_day(workers, number_of_workers) << endl << "#" << endl;
    cout << calculate_max_interval(workers, number_of_workers) << endl << "#" << endl;
    empty_days(workers, number_of_workers);

    return 0;
}

int calculate_total_wage(worker workers[], int size)
{
    int total_wage = 0;
    for(int i = 0; i < size; i++)
    {
        total_wage += (workers[i].day_end - workers[i].day_start +1) * workers[i].salary;
    }
    return total_wage;
}

int calculate_days_worked_of_max_salary(worker workers[], int size)
{
    // ez meg lehet oldani egyetlen ciklussal, de inkább hosszabban írom le hátha úgy érthetőbb

    // kiszámoljuk az összes jövedelmet
    int wages[size];
    for(int i = 0; i < size; i++)
    {
        wages[i] = (workers[i].day_end - workers[i].day_start + 1) * workers[i].salary;
    }

    // megkeressük a jövedelmek maximumát
    int max_wage = 0;
    for(int i = 0; i < size; i++)
    {
        if(wages[i] > max_wage)
        {
            max_wage = wages[i];
        }
    }

    // megkeressük azt a workert akinek a max_wage a jövedelme
    bool found = false;
    int workers_iterator = 0;
    int days_worked = 0;
    while(!found)
    {
        if((workers[workers_iterator].salary * (workers[workers_iterator].day_end - workers[workers_iterator].day_start + 1)) == max_wage)
        {
            found = true;
            days_worked = workers[workers_iterator].day_end - workers[workers_iterator].day_start + 1;
        }
        workers_iterator++;
    }

    return days_worked;
}

int calculate_max_numer_of_workers_on_the_same_day(worker workers[], int size)
{

    int earliest_start = 10000000;
    int latest_end = 0;

    for(int i = 0; i < size; i++)
    {
        if(workers[i].day_start < earliest_start)
        {
            earliest_start = workers[i].day_start;
        }

        if(workers[i].day_end > latest_end)
        {
            latest_end = workers[i].day_end;
        }
    }

    int days_range = latest_end - earliest_start + 1;
    int number_of_ppl_each_day[days_range];
    for(int i = 0; i < days_range; i++)
    {
        number_of_ppl_each_day[i] = 0;
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = workers[i].day_start; j < workers[i].day_end; j++)
        {
            number_of_ppl_each_day[days_range-j]++;
        }
    }

    int max_number_of_workers_on_same_day = 0;
    for(int i = 0; i < days_range; i++)
    {
        if(number_of_ppl_each_day[i] > max_number_of_workers_on_same_day)
        {
            max_number_of_workers_on_same_day = number_of_ppl_each_day[i];
        }
    }

    return max_number_of_workers_on_same_day;
}

int calculate_max_interval(worker workers[], int size)
{
    // UGYANAZ MINT AZ ELŐZŐ FÜGGVÉNYBEN
    int earliest_start = numeric_limits<int>::max();
    int latest_end = 0;

    for(int i = 0; i < size; i++)
    {
        if(workers[i].day_start < earliest_start)
        {
            earliest_start = workers[i].day_start;
        }

        if(workers[i].day_end > latest_end)
        {
            latest_end = workers[i].day_end;
        }
    }

    int days_range = latest_end - earliest_start + 1;
    int number_of_ppl_each_day[days_range];

    for(int i = 0; i < size; i++)
    {
        for(int j = workers[i].day_start; j < workers[i].day_end; j++)
        {
            number_of_ppl_each_day[j-days_range]++;
        }
    }

    int max_number_of_workers_on_same_day = 0;
    for(int i = 0; i < days_range; i++)
    {
        if(number_of_ppl_each_day[i] > max_number_of_workers_on_same_day)
        {
            max_number_of_workers_on_same_day = number_of_ppl_each_day[i];
        }
    }
    // /////////////////////////////////

    int max_interval = 0;
    int interval_counter = 1;
    for(int i = 0; i < days_range; i++)
    {
        if(number_of_ppl_each_day[i] == max_number_of_workers_on_same_day)
        {
            interval_counter++;
            if(max_interval < interval_counter)
            {
                max_interval = interval_counter;
            }
        }
        else
        {
            interval_counter = 1;
        }
    }

    return max_interval;
}

void empty_days(worker workers[], int size)
{
    int latest_end = 0;
    for(int i = 0; i < size; i++)
    {
        if(latest_end < workers[i].day_end)
            latest_end = workers[i].day_end;
    }

    int workers_on_each_day_from_day_zero[latest_end];
    for(int i = 0; i < latest_end; i++)
    {
        workers_on_each_day_from_day_zero[i] = 0;
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = workers[i].day_start-1; j < workers[i].day_end; j++)
        {
            workers_on_each_day_from_day_zero[j]++;
        }
    }

    for(int i = 1; i < latest_end-1; i++)
    {
        if((workers_on_each_day_from_day_zero[i-1] != 0) && (workers_on_each_day_from_day_zero[i] == 0))
        {
            cout << i+1 << " ";
        }

        if((workers_on_each_day_from_day_zero[i] == 0) && (workers_on_each_day_from_day_zero[i+1] != 0))
        {
            cout << i+1 << endl;
        }
    }

}

//bool empty_days(worker workers[], int size)
//{
//    int earliest_start = numeric_limits<int>::max();
//    int latest_end = 0;

//    for(int i = 0; i < size; i++)
//    {
//        if(workers[i].day_start < earliest_start)
//        {
//            earliest_start = workers[i].day_start;
//        }

//        if(workers[i].day_end > latest_end)
//        {
//            latest_end = workers[i].day_end;
//        }
//    }

//    int days_range = latest_end - earliest_start + 1;
//    int number_of_ppl_each_day[days_range];

//    for(int i = 0; i < size; i++)
//    {
//        for(int j = workers[i].day_start; j < workers[i].day_end; j++)
//        {
//            number_of_ppl_each_day[j-days_range]++;
//        }
//    }

//    bool is_there_an_empty_day = false;
//    int array_iterator = 0;
//    while(!is_there_an_empty_day && array_iterator < days_range)
//    {
//        if(number_of_ppl_each_day[array_iterator] == 0)
//        {
//            return true;
//        }
//        array_iterator++;
//    }
//    return false;
//}
