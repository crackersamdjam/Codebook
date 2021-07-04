### Reversable Functions

Standard BIT supports the following for reversable functions:
- point update + point query
- point update + range query
- range update + point query

To do range update + range query, use range_bit.

### Non-reversable Functions

The only operations supported for non-reversable functions are:
- point update + prefix query
- suffix update + point query
