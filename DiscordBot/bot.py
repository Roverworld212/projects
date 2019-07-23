#Made for CatBoat
#Add your database to it and make more templates
#The purpose of this it to create random wyr questions (Surprise they won't make sense)
#Three simple templates are already made and this code could (and should) be optimized (probably)
import discord
import sqlite3
import random
from discord.ext import commands

client = commands.Bot(command_prefix = '!')

@client.event
async def on_ready():
    print('Bot is ready to slam and jam')

@client.command()
async def rwyr(ctx):
    i = random.randint(1,3)
    if i == 1:
        msg = await ctx.send(template_1())
    elif i == 2:
        msg = await ctx.send(template_2())
    elif i == 3:
        msg = await ctx.send(template_3())
    await msg.add_reaction("\U0001F1E6")
    await msg.add_reaction("\U0001F171")
    await msg.add_reaction("\U000023E9")

@client.command()
async def frt(ctx, *, tnum):
    print(tnum)
    if tnum == '1':
        msg = await ctx.send(template_1())
    elif tnum == '2':
        msg = await ctx.send(template_2())
    elif tnum == '3':
        msg = await ctx.send(template_3())
    else:
        msg = await ctx.send('Not valid')
        return
    await msg.add_reaction("\U0001F1E6")
    await msg.add_reaction("\U0001F171")
    await msg.add_reaction("\U000023E9")



def get_noun():
    conn = sqlite3.connect('test.db')
    cursor = conn.cursor()
    cursor.execute("SELECT plural FROM nouns ORDER BY RANDOM() LIMIT 1")
    result = cursor.fetchone()[0]
    conn.close()
    return result

def get_verb(i):
    conn = sqlite3.connect('test.db')
    cursor = conn.cursor()
    if i != 'ving':
        cursor.execute("SELECT plural FROM verbs ORDER BY RANDOM() LIMIT 1")
        result = cursor.fetchone()[0]
    else:
        cursor.execute("SELECT ving FROM verbs ORDER BY RANDOM() LIMIT 1")
        result = cursor.fetchone()[0]
    conn.close()
    return result

def template_1():
    mtr = 'Would you rather\n' + '\U0001F1E6' + '`' + 'buy ' + get_noun() + '`' + '\n' + '\U0001F171' + '`' + 'buy ' + get_noun() + '`\n' + '\U000023E9' + '`I rather not answer`'
    return mtr

def template_2():
    mtr = 'Would you rather\n' + '\U0001F1E6' + '`' + get_verb('s') + '`' + '\n' + '\U0001F171' + '`' + get_verb('s') + '`\n' + '\U000023E9' + '`I rather not answer`'
    return mtr

def template_3():
    mtr = 'Would you rather\n' + '\U0001F1E6' + '` Buy ' + get_noun() + ' and bring it to ' + get_noun() + '`\n' + '\U0001F171' + '`' + get_verb('s') + '`\n' + '\U000023E9' + '`I rather not answer`'
    return mtr


client.run('Token')
