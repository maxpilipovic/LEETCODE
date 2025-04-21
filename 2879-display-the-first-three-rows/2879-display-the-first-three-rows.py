import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    rows = []
    count = 0
    for index, row in employees.iterrows():
        
        if count < 3:
            #Do something
            rows.append(row)
        count += 1

    return pd.DataFrame(rows)
