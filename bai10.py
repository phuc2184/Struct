import pandas as pd 
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

data = {
    "name" : ["nam","an","binh"],
    "age"  : [20,21,20],
    "ml_score" : [6.8,8.0,9.5],
    "python_score" : [4.5,4.9,5]
}
df=pd.DataFrame(data)
top3=df.sort_values(by="ml_score",ascending=False).head(1)
df["python_score"]=(df["python_score"]-df["python_score"].min())/(df["python_score"].max()-df["python_score"].min())
df.to_csv("dataset.csv",index=False)
df=pd.read_csv("dataset.csv")
X = df[["ml_score"]]   # 2 dấu []
y = df["python_score"] # 1 dấu []
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3) 
model = LinearRegression() 
model.fit(X_train, y_train) 
print("Predict:", model.predict(X_test))

print("Average python",df["python_score"].mean())
print("\nSINH VIEN CO DIEM CAO NHAT\n", top3)
print("BANG DIEM PYTHON DA CHUAN HOA\n ",df["python_score"])
print(df)


