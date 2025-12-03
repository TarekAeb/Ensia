## 
A **stochastic process** is a collection of random variables, usually indexed by time, representing the evolution of some system or phenomenon over time. For each point in time, the random variable gives the state of the system at that time.

##
**Markov Property:** It is indeed a special case of a stochastic process where the future state of the system depends only on its current state, and not on the sequence of events that preceded it. It essentially means that the "memory" of the process only extends to the most recent state. This simplifies analysis greatly. Mathematically, if X_t is the state of time t then P(X_t+1 | X_t,X_t-1,...,X_0) = P(X_t+1 | X_t)

**Discrete vs. Continuous Time:** You're spot on with the two main types based on how time evolves:

- Discrete-Time Markov Chain (DTMC): The system changes states at specific, fixed points in time (e.g., every second, every day, at specific steps). This is what your Chapter 1 focuses on. The transitions happen "instantaneously" at these discrete time steps.
- Continuous-Time Markov Chain (CTMC): The system can change states at any moment in time. The time spent in a state before transitioning to another state is a continuous random variable (often exponentially distributed). This will be covered in your Chapter 2.


## DTMC

1.  **States (Circles/Nodes):** You correctly identified that the "circles" or nodes in a diagram represent the **states** of the system. These are the possible conditions or configurations the system can be in. For example, in a weather model, states could be "Sunny," "Cloudy," "Rainy." In a game, states could be "Player 1's Turn," "Player 2's Turn," "Game Over."

2.  **Transitions (Arrows/Edges):** The "arrows" or edges between states represent the **transitions** between them. Crucially, these arrows are associated with **transition probabilities**, which tell us the likelihood of moving from one state to another in a single time step.

3.  **Transition Matrix:** You've nailed the definition of the **transition probability matrix (P)**.
    *   It's a square matrix where rows represent the **current state** and columns represent the **next state**.
    *   The entry $P_{ij}$ (at row *i*, column *j*) is the probability of transitioning from state *i* to state *j* in one time step: $P(X_{t+1} = j | X_t = i)$.
    *   Key properties of this matrix:
        *   All entries $P_{ij}$ must be non-negative: $P_{ij} \ge 0$.
        *   The sum of probabilities in each row must equal 1 (since the process *must* transition to some state from the current one): $\sum_{j} P_{ij} = 1$ for all *i*.
