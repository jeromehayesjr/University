
/*


+----------------------------------------------------+
|                                                    |
| Number                                             |
|                                                    |
|                                                    |
+----------------------------------------------------|
|                                                    |
| -n : int                                           |
|                                                    |
|                                                    |
+----------------------------------------------------+
|                                                    |
|  + Number(n : int)                                  |
|  + isPrime() : bool                                |
|   + is DivisibleBy (k : int) : bool                |
|                                                    |
|                                                    |
+----------------------------------------------------+
*/

class Number
{
public:
	Number(int n);
	bool isPrime() const;
	bool isDivisibleBy(int k) const;

private:
    int n;
};
