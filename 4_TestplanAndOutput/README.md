# Test plan
# High_Level
Test Plan | Description | Exp I/P | Exp O/P | Actual O/P | Type of Test 
|:--:|:--:|:--:|:--:|:--:|:--:|
| H_01| User Input | 3 | Search for particular invoice | Inovice | Input test |
| H_02| User Input | 5 | Sorry....Invalid Option | Re-enter the value | Invalid input |
| H_03| Save file | Y | File Saved Successfully | File Saved  | File Saving |
| H_04| Save file | G | Enter Correct value | Follows the next step  | Wrong Input |



# Low_Level
Test Plan | Description | Exp I/P | Exp O/P | Actual O/P | Type of Test 
|:--:|:--:|:--:|:--:|:--:|:--:|
|L_01| Total worth calculation | 3, 200 | 600 | 600 | Calculation|
|L_02| Total worth calculatiion | 0 , 20 | 0 | 0 | Zero Total |
|L_03| Total after discount | 450 | 360 | 360 | Discount calcualtion |
|L_04| Total after discount | 2156.25 | 1725 | 1725 |Float calculation | 
|L_05| Adding GST | 950 | 1121 | 1121 | GST calculation | 
|L_06| Adding GST | 6560 | 7740.80 | 7740.80 | GST float calculation

