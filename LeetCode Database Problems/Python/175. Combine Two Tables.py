import pandas as pd


def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    df_res = pd.merge(person, address, on='personId', how='left')
    return df_res[['firstName', 'lastName', 'city', 'state']]


if __name__ == '__main__':
    data = [[1, 'Wang', 'Allen'], [2, 'Alice', 'Bob']]
    person = pd.DataFrame(data, columns=['personId', 'firstName', 'lastName']).astype({'personId':'Int64', 'firstName':'object', 'lastName':'object'})
    data = [[1, 2, 'New York City', 'New York'], [2, 3, 'Leetcode', 'California']]
    address = pd.DataFrame(data, columns=['addressId', 'personId', 'city', 'state']).astype({'addressId':'Int64', 'personId':'Int64', 'city':'object', 'state':'object'})
    df_res = combine_two_tables(person, address)
    print(df_res)
