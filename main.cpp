#include <iostream>

using namespace std;

struct worker
{
    int day_start;
    int day_end;
    int salary;
};

int main()
{

    //   ___  _   _  ____   _   _  _____
    //  |_ _|| \ | ||  _ \ | | | ||_   _|
    //   | | |  \| || |_) || | | |  | |
    //   | | | |\  ||  __/ | |_| |  | |
    //  |___||_| \_||_|     \___/   |_|
    //
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

    cout << "#" << endl;
    //   _
    //  / |
    //  | |
    //  | |
    //  |_|
    //
    int total_wage = 0;
    for(int i = 0; i < size; i++)
    {
        total_wage += (workers[i].day_end - workers[i].day_start +1) * workers[i].salary;
    }
    cout << total_wage << endl;

    cout << "#" << endl;
    //   ____
    //  |___ \
    //    __) |
    //   / __/
    //  |_____|
    //

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

    cout << days_worked << endl;

    cout << "#" << endl;
    //   _____
    //  |___ /
    //    |_ \
    //   ___) |
    //  |____/
    //
    int latest_end = 0;
    for(int i = 0; i < size; i++)
    {
        if(workers[i].day_end > latest_end)
        {
            latest_end = workers[i].day_end;
        }
    }

    int max_workers_on_a_day[latest_end];
    for(int i = 0; i < latest_end; i++)
    {
        max_workers_on_a_day[i] = 0;
    }

    for(int i = 0; i < number_of_workers; i++)
    {
        for(int j = workers[i].day_start-1; j < workers[i].day_end; j++)
        {
            max_workers_on_a_day[j]++;
        }
    }

    int max_number_of_ppl_on_a_day = 0;
    for(int i = 0; i < latest_end; i++)
    {
        if(max_number_of_ppl_on_a_day < max_workers_on_a_day[i])
            max_number_of_ppl_on_a_day = max_workers_on_a_day[i];
    }

    cout << max_number_of_ppl_on_a_day << endl;

    cout << "#" << endl;
    //   _  _
    //  | || |
    //  | || |_
    //  |__   _|
    //     |_|
    //
    int max_interval = 0;
    int interval_counter = 1;
    for(int i = 0; i < days_range; i++)
    {
        if(max_workers_on_a_day[i] == max_number_of_ppl_on_a_day)
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

    cout << max_interval << endl;

    cout << "#" << endl;
    //   ____
    //  | ___|
    //  |___ \
    //   ___) |
    //  |____/
    //
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

    return 0;
}
