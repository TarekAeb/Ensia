import matplotlib.pyplot as plt
import seaborn as sns
#from sklearn.metrics import confusion_matrix, classification_report, accuracy_score
import numpy as np
import pandas as pd
import seaborn as sns
from sklearn.metrics import confusion_matrix, accuracy_score, precision_recall_fscore_support, classification_report




def visualize_test_results(y_true, y_pred, class_names=None, model_name="Model"):
    """
    Visualize test results with confusion matrix and classification metrics.

    Parameters:
    y_true : array-like, true labels
    y_pred : array-like, predicted labels
    class_names : list, optional, names of classes (e.g., iris.target_names)
    model_name : str, name of the model for titles
    """
    # Compute metrics
    accuracy = accuracy_score(y_true, y_pred)
    cm = confusion_matrix(y_true, y_pred)
    report = classification_report(y_true, y_pred, target_names=class_names, output_dict=True)

    # Create figure with two subplots
    fig, axes = plt.subplots(1, 2, figsize=(14, 5))

    # 1. Confusion Matrix
    sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', 
                xticklabels=class_names, yticklabels=class_names, ax=axes[0])
    axes[0].set_xlabel('Predicted')
    axes[0].set_ylabel('True')
    axes[0].set_title(f'{model_name} - Confusion Matrix\nAccuracy: {accuracy:.4f}')

    # 2. Bar plot of precision, recall, f1-score per class
    metrics_df = pd.DataFrame(report).iloc[:-1, :3]  # exclude support and avg rows
    metrics_df.plot(kind='bar', ax=axes[1], rot=0)
    axes[1].set_title(f'{model_name} - Classification Metrics')
    axes[1].set_ylabel('Score')
    axes[1].set_xlabel('Class')
    axes[1].legend(loc='lower right')
    axes[1].set_ylim(0, 1.1)
    for container in axes[1].containers:
        axes[1].bar_label(container, fmt='%.2f', padding=3)

    plt.tight_layout()
    plt.show()


#visualize_test_results(y_valid, y_pred_1,  class_names=iris.target_names,
#                       model_name="Decision Tree (Validation)")

def compare_models_validation(results_list, class_names=None):
    """
    Compare multiple models on validation data.

    Parameters:
    results_list : list of tuples, each containing (y_true, y_pred, model_name)
    class_names : list, optional, names of classes
    """
    n_models = len(results_list)
    # Adjust subplot layout: 2 rows, n_models columns
    if n_models == 1:
        fig, axes = plt.subplots(2, 1, figsize=(5, 8))
        axes = axes.reshape(2, -1)  # make it 2D for consistent indexing
    else:
        fig, axes = plt.subplots(2, n_models, figsize=(5*n_models, 8))

    for i, (y_true, y_pred, model_name) in enumerate(results_list):
        # Compute metrics
        cm = confusion_matrix(y_true, y_pred)
        acc = accuracy_score(y_true, y_pred)
        precision, recall, f1, _ = precision_recall_fscore_support(y_true, y_pred)

        # Determine class labels for display
        if class_names is None:
            labels = [str(c) for c in np.unique(np.concatenate([y_true, y_pred]))]
        else:
            # Ensure class_names is a list and matches number of classes
            labels = list(class_names)
            if len(labels) != len(precision):
                # Fallback to numeric labels if mismatch
                labels = [str(i) for i in range(len(precision))]

        # Top row: confusion matrix
        sns.heatmap(cm, annot=True, fmt='d', cmap='Blues',
                    xticklabels=labels, yticklabels=labels,
                    ax=axes[0, i])
        axes[0, i].set_title(f'{model_name}\nAccuracy: {acc:.3f}')
        axes[0, i].set_xlabel('Predicted')
        axes[0, i].set_ylabel('True')

        # Bottom row: metrics bar chart
        metrics_df = pd.DataFrame({
            'Precision': precision,
            'Recall': recall,
            'F1-Score': f1
        }, index=labels)
        metrics_df.plot(kind='bar', ax=axes[1, i], rot=0)
        axes[1, i].set_title(f'{model_name} - Per-class Metrics')
        axes[1, i].set_ylim(0, 1.1)
        axes[1, i].legend(loc='lower right')

    plt.tight_layout()
    plt.show()
    
"""results = [
    (y_valid, y_pred_1, "Decision Tree"),
    (y_valid, y_pred_2, "Random Forest"),
    (y_valid, y_pred_3, "SVM")
]
compare_models_validation(results, class_names=iris.target_names)
"""
