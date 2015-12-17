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

### Assume that the duration, departure time and return time are as follows:
```
total trip days:           3
departure time:         8:00
return time:           21:00
```

### Airfair                
If user enter 300 for total airfair...
```
Total expenses:          $  300
Allowable expenses:      $  300
Out out pocket:          $  0
Saved                    $  0
```

### Car rental         
If user enter 200 for total car rental fees...
```
Total expenses:          $  200
Allowable expenses:      $  200
Out out pocket:          $  0
Saved                    $  0
```

### Private vehicle  
If user enter 50 for milage driven by private vehicle...
```
Total expenses:          50 mile  * $ 0.27 = $13.50  
Allowable expenses:      $  13.50
Out out pocket:          $  0
Saved                    $  0
```

### Parking          
If user enter 30 for total parking fees...
```
Total expenses:          $  30
Allowable expenses:      $  18
Out out pocket:          $  12
Saved                    $  0
```

### Taxi              
If user enter 50 for total taxi fees...
```
Total expenses:          $  50
Allowable expenses:      $  30
Out out pocket:          $  20
Saved                    $  0
```

### Registration      
If user enter 50 for total registration fees...
```
Total expenses:          $  50
Allowable expenses:      $  50
Out out pocket:          $  0
Saved                    $  0
```

### Hotel 
If user enter 100 for nightly hotel room rate...

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

### Meals

Company max for each day
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

If user enter the following values for the meals...
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

Allowable expenses for each meal
```
----[Day 1]----
         totalSpent  totalAllowed
Lunch:     10         12
Dinner:    20         16
----[Day 2]----
Breakfast:  8          9
Lunch:     12         12
Dinner:    23         16
----[Day 3]----
Breakfast: 10          9
Lunch:     13         12
Dinner:    16         16
```

For all the meals
```
Total expenses:     $  112
Allowable expenses: $  102
Out out pocket:     $   10
Saved               $    0
```

### Totals

```
Total days:     03
Departure time: 08:00
Return time:    21:00

Total expenses:     $  955.50
Allowable expenses: $  893.50
Out of pocket:      $   62.00
```

