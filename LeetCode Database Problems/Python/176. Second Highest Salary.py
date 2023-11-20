import pandas as pd


def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    sorted_salaries = employee['salary'].sort_values(ascending=False).drop_duplicates()

    if len(sorted_salaries) > 1:
        second_highest = sorted_salaries.loc[1]
    else:
        second_highest = None

    return pd.DataFrame({'SecondHighestSalary': [second_highest]})
