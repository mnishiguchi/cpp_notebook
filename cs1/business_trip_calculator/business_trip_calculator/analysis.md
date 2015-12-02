# BusinessTripCalculator

## ANALYSIS

### Assume that the company's rules are as follows:
```
PRIVATE_CAR_MILAGE_ALLOWANCE =  0.27;
MAX_DAILY_PARKING_FEE        =  6.00;
MAX_DAILY_TAXI_FEE           = 10.00;
MAX_HOTEL_RATE_PER_NIGHT     = 90.00;
MAX_DAILY_BREAKFAST          =  9.00;
MAX_DAILY_LUNCH              = 12.00;
MAX_DAILY_DINNER             = 16.00;
```

### Assume that the trip's duration, departure time and return time are as follows:
```
total trip days:           3
departure time:         8:00
return time:           21:00
```

### Airfair                
If user enter 300 for total airfair,
```
**TODO**
Total expenses:          $  ???
Allowable expenses:      $  ???
Out out pocket:          $  ???
Saved                    $  ???
```

### car rental         
If user enter 200 for total car rental fees,
```
**TODO**
Total expenses:          $  ???
Allowable expenses:      $  ???
Out out pocket:          $  ???
Saved                    $  ???
```

### private vehicle  
If user enter 50 for milage driven by private vehicle
```
**TODO**
Total expenses:          $  ???
Allowable expenses:      $  ???
Out out pocket:          $  ???
Saved                    $  ???
```

### parking          
If user enter 30 for total parking fees
```
**TODO**
Total expenses:          $  ???
Allowable expenses:      $  ???
Out out pocket:          $  ???
Saved                    $  ???
```

### taxi              
If user enter 50 for total taxi fees
```
**TODO**
Total expenses:          $  ???
Allowable expenses:      $  ???
Out out pocket:          $  ???
Saved                    $  ???
```

### registration      
If user enter 50 for total registration fees
```
**TODO**
Total expenses:          $  ???
Allowable expenses:      $  ???
Out out pocket:          $  ???
Saved                    $  ???
```

### hotel 
If user enter 100 for nightly hotel room rate:

- since the duration is longer than one day, hotel stay is allowed;
- number of hotel stay: 3 - 1 = 2 nights;
- totalSpent   = 100 * 2 = 200;
- companyMax   =  90;
- totalAllowed =  90 * 2 = 180;

```
Total expenses:          $  200
Allowable expenses:      $  180
Out out pocket:          $   20
Saved                    $    0
```

### meals

Company max
```
MAX_DAILY_BREAKFAST =  9.00;
MAX_DAILY_LUNCH     = 12.00;
MAX_DAILY_DINNER    = 16.00;
```

Meals allowed
```
----[Day 1]----
- breakfast:  No   // breakfast not allowed due to departuer after 7am
- lunch:      Yes
- dinner:     Yes
----[Day 2]----
- breakfast:  Yes
- lunch:      Yes
- dinner:     Yes
----[Day 3]----
- breakfast:  Yes
- lunch:      Yes
- dinner:     Yes
```

If user enter the following values for the meals:
```
----[Day 1]----
Lunch:     10
Dinner:    20
----[Day 2]----
Breakfast:  8
Lunch:     12
Dinner:    23
----[Day 3]----
Breakfast: 10
Lunch:     13
Dinner:    16
```

```
----[Day 1]----
         totalSpent  totalAllowed  outOfPocket   saved
Lunch:     10         10                0           2 
Dinner:    20         16                4           0
----[Day 2]----
Breakfast:  8          8                0           1 
Lunch:     12         12                0           0 
Dinner:    23         16                7           0 
----[Day 3]----
Breakfast: 10          9                1           0 
Lunch:     13         12                1           0 
Dinner:    16         16                0           0
```

```
Total expenses:          $  112
Allowable expenses:      $   99
Out out pocket:          $   13
Saved                    $    3
```

### totals
We put together all the values above.

```
**TODO**
Total expenses:          $  ???
Allowable expenses:      $  ???
Out out pocket:          $  ???
Saved                    $  ???
```

==

## OUTPUT

```
How many days did you spent on this trip? 
>>> 3
Departure time, in 24-hour time: 
>>> 8.00
Return time, in 24-hour time: 
>>> 21.00
Total amount of airfair: 
>>> 300
Total amount of car rental fees: 
>>> 200
Total miles driven by a private vehicle: 
>>> 50
Total amount of parking fees: 
>>> 30
Total amount of taxi fees: 
>>> 50
Total amount of registration fees: 
>>> 50
Nightly hotel rate: 
>>> 100
----[Day 1]----
Lunch: 
>>> 10
Dinner: 
>>> 20
----[Day 2]----
Breakfast: 
>>> 8
Lunch: 
>>> 12
Dinner: 
>>> 23
----[Day 3]----
Breakfast: 
>>> 10
Lunch: 
>>> 13
Dinner: 
>>> 16
```

```
Total days:    03
departureTime: 08:00
returnTime:    21:00

Total expenses:     $  955.50
Allowable expenses: $  893.50
Out of pocket:      $   65.00
Amount saved:       $    3.00
```
