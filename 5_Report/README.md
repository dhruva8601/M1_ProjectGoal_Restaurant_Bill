# Project Report

         This project is helpful for small scale restaurant owners, who can't afford their budget on billing software. 
         It is available 24*7 and is feasible to bussiness owners

## Features of the project
         This project's key features are :
         * You can add CGST and SGST in your bill
         * You can give discount on total to customer
         * You can store the Invoice of a customer, and fetch it whenever is necessary
         * You can delete a particular Invoice, if not necessary
         * Make an easy to use environment for users and customers

## Identifying the Requirements
     Technologies and Tools Used:
     
         * Web Technology: Chrome
         * Development Tool: Github Website
         * Web browser: Google Chrome Latest
         * Languages Used: C Language
         * Hardware CPU configuration

## Swot Analysis 
        * Strenght :
             Inclusive of GST taxes and searching the previous invoices
        * Weakness :
             Payment gateways, QR code are not added, but in future I will make this feature enable and make this a strenght
        * Opportunity :
             For Small scale business owners, it is a very good application and it saves a lot of time and money
        * Threats :
             This application is vulnerable to virus threats
             
## Highlevel Requirements
|ID|Description|Status|
|:--:|:--:|:--:|
|HLR_01|This project helps to store Invoices|Implemented|
|HLR_02|This project helps to fetch previous invoices|Implemented|
|HLR_03|This project helps to delete previous Invoices|Implemented|
|HLR_04|Payment Gateways and QR codes|Future|

    
## Lowlevel Requirements
|ID|Description|Status|
|:--:|:--:|:--:|
|LLR_01|This project calculates total with discount|Implemented|
|LLR_02|This project calculates grand total with GST|Implemented|
|LLR_03|Prints Invalid message if entered wrong input|Implemented|             
             

## Architecture
![High_Level_Behavioural_diagram](https://user-images.githubusercontent.com/56836409/152368189-5a6bc597-2372-4629-a718-7c49a529bbdb.png)





![High_Level_Structural_diagram](https://user-images.githubusercontent.com/56836409/152926553-beebae39-42f6-4d8a-bdf8-89b71054689d.png)



## Implementation
* Instructions to RUN program
1. Clone my repository into your system
2. You should go to 3_Implementation/ folder
3. Run "make run" command in your terminal for execution of program


## Folder description
|Folder|Description|
|:--:|:--:|
|`inc`| contains all header files|
|`src`| contains source code file|
|`unit`| conatins files for unit testing|



## Test plan
### High_Level
Test Plan | Description | Exp I/P | Exp O/P | Actual O/P | Type of Test 
|:--:|:--:|:--:|:--:|:--:|:--:|
| H_01| User Input | 3 | Search for particular invoice | Inovice | Input test |
| H_02| User Input | 5 | Sorry....Invalid Option | Re-enter the value | Invalid input |
| H_03| Save file | Y | File Saved Successfully | File Saved  | File Saving |
| H_04| Save file | G | Enter Correct value | Follows the next step  | Wrong Input |



### Low_Level
Test Plan | Description | Exp I/P | Exp O/P | Actual O/P | Type of Test 
|:--:|:--:|:--:|:--:|:--:|:--:|
|L_01| Total worth calculation | 3, 200 | 600 | 600 | Calculation|
|L_02| Total worth calculatiion | 0 , 20 | 0 | 0 | Zero Total |
|L_03| Total after discount | 450 | 360 | 360 | Discount calcualtion |
|L_04| Total after discount | 2156.25 | 1725 | 1725 |Float calculation | 
|L_05| Adding GST | 950 | 1121 | 1121 | GST calculation | 
|L_06| Adding GST | 6560 | 7740.80 | 7740.80 | GST float calculation
