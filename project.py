import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import MultinomialNB
from sklearn import preprocessing
from sklearn.naive_bayes import GaussianNB
from sklearn import metrics
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import classification_report,confusion_matrix
from sklearn.model_selection import GridSearchCV

# Load data file
filename = '/Users/zach/Desktop/AI_Project/venv/data'
a = np.loadtxt(filename, dtype= np.unicode,delimiter=',')
# print shape
#print(a.shape)

# create empty array of data shape
arr = np.empty(a.shape, dtype=int)
# check to make sure shapes are the same
#print(arr.shape)

# Transform data into integers
le = preprocessing.LabelEncoder()
for i in range (23):
   arr[:,i] = le.fit_transform(a[:,i])

# Split into  X input features and  Y output, test and training
X = arr[:,1:]
y = arr[:,0]

# REDUCED TRAINING SIZE
X_train, X_test, y_train, y_test = train_test_split(X,y,random_state=42, train_size=0.025)

# Naive's classifier
model = MultinomialNB(alpha=0.01, fit_prior=True)
model.fit(X_train,y_train)
pred_train = model.predict(X_train)

# Training accuracy
#print(pred_train)
print("Training acc: " , metrics.accuracy_score(y_train, pred_train) )

# Test accuracy
model.fit(X_test,y_test)
pred_test = model.predict(X_test)
print("Testing acc: " , metrics.accuracy_score(y_test, pred_test) )

# MLP Classifier Step #6
mlp = MLPClassifier(alpha=0.1, max_iter=5000, hidden_layer_sizes=(300,300))

net = mlp.fit(X_train, y_train)

# Get predictions; to build confusion matrix and other calculations
predictions = net.predict(X_test)

# Calculate accuracy
score = net.score(X_test,y_test)
print("\n\nAccuracy score: ", score)

# Number of iterations
print("Iterations: ", net.n_iter_)

# Calculate confusion matrix
# print("Confusion Matrix:\n", confusion_matrix(y_test,predictions))

# Classification report
# print("\nClassification Report:\n",classification_report(y_test,predictions))

# Parameter arrays
alphas = [.01, .10, .20, .30, .40, .50]
iterations = [4000, 5000]
hidden_layers = ((100,100), (200,200), (300,300), (100,10,1))
prior_fit = [True, False]

# STEP 2 parameter dictionary from param arrays
mlp_params = dict(alpha=alphas, max_iter = iterations, hidden_layer_sizes = hidden_layers)
naive_params = dict(alpha = alphas, fit_prior = prior_fit)
# STEP 3 grid search and fit data
grid_search = GridSearchCV(MLPClassifier(), cv=5, param_grid=mlp_params)
grid_search.fit(X_train, y_train)

# STEP 4 best params and score
print("Score: ",grid_search.score(X_train, y_train))
print("Best params: ",grid_search.best_params_)

