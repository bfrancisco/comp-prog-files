def f(n):
  if (n == 0):
    return 2
  elif n == 1:
    return 1
  
  return f(n-2) + f(n-1)
 
print(f(int(input())))

# class team_name:
#     def magis(self):
#         ## code
#         print("Hello World!")

# omsim = team_name()
# omsim.magis()