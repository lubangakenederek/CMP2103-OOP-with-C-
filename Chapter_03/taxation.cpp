// The income tax rate for individuals in business depends on the income bracket in which the individual falls.
// Resident individuals enjoy a tax free annual income threshold of UGX. 2,820,000 per annum. The
// balance is taxed at 10%, 20% or 30% depending on the income bracket. Individuals who earn
// above UGX 120,000,000 pa pay an additional 10% on the income above 120m.
// +----------------------+------------------------------------------+------------------------------------------+
// | CHARGEABLE INCOME, CY| RESIDENTS                                | NON-RESIDENTS                             |
// | (UGX Annual)         | RATE OF TAX                              | RATE OF TAX                               |
// +----------------------+------------------------------------------+------------------------------------------+
// | 0 to 2,820,000       | Nil                                      | CY x 10%                                  |
// | 2,820,000 to         | (CY - 2,820,000) x 10%                   | CY x 10%                                  |
// | 4,020,000            |                                          |                                           |
// | 4,020,000 to         | (CY - 4,020,000) x 20% + 120,000         | (CY - 4,020,000) x 20% + 402,000          |
// | 4,920,000            |                                          |                                           |
// | 4,920,000 to         | (CY - 4,920,000) x 30% + 300,000         | (CY - 4,920,000) x 30% + 582,000          |
// | 120,000,000          |                                          |                                           |
// | Above 120,000,000    | [(CY - 4,920,000) x 30% + 300,000]       | [(CY - 4,920,000) x 30% + 582,000]        |
// |                      | + [(CY - 120,000,000) x 10%]             | + [(CY - 120,000,000) x 10%]              |
// +----------------------+------------------------------------------+------------------------------------------+

// You are to write a program to compute personal income tax. Your program should prompt
// the user to enter the residence status and taxable income and then compute the tax. Enter 0 for
// resident and 1 for non-resident.

// Output
// (0-Resident, 1-Non-resident)
// Enter the residence status: 0
// Enter the taxable income: 4,000,000
// Tax is 118000.
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int residenceStatus;
    double chargeableIncome;
    double tax = 0.0;

    // Prompt user for input
    cout << "(0-Resident, 1-Non-resident)" << endl;
    cout << "Enter the residence status: ";
    cin >> residenceStatus;
    
    cout << "Enter the taxable income: ";
    cin >> chargeableIncome;

    // Compute tax based on residence status
    if (residenceStatus == 0) {
        // Resident Tax Calculation
        if (chargeableIncome <= 2820000) {
            tax = 0.0;
        } 
        else if (chargeableIncome <= 4020000) {
            tax = (chargeableIncome - 2820000) * 0.10;
        } 
        else if (chargeableIncome <= 4920000) {
            tax = (chargeableIncome - 4020000) * 0.20 + 120000;
        } 
        else if (chargeableIncome <= 120000000) {
            tax = (chargeableIncome - 4920000) * 0.30 + 300000;
        } 
        else {
            // Above 120,000,000
            tax = ((chargeableIncome - 4920000) * 0.30 + 300000) + ((chargeableIncome - 120000000) * 0.10);
        }
    } 
    else if (residenceStatus == 1) {
        // Non-Resident Tax Calculation
        if (chargeableIncome <= 4020000) {
            tax = chargeableIncome * 0.10;
        } 
        else if (chargeableIncome <= 4920000) {
            tax = (chargeableIncome - 4020000) * 0.20 + 402000;
        } 
        else if (chargeableIncome <= 120000000) {
            tax = (chargeableIncome - 4920000) * 0.30 + 582000;
        } 
        else {
            // Above 120,000,000
            tax = ((chargeableIncome - 4920000) * 0.30 + 582000) + ((chargeableIncome - 120000000) * 0.10);
        }
    } 
    else {
        cout << "Invalid residence status entered!" << endl;
        return 1;
    }

    // Output the computed tax without scientific notation
    cout << fixed << setprecision(0);
    cout << "Tax is " << tax << "." << endl;

    return 0;
}
