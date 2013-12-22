# About #
__todocmd__ is a command-line based todo application written in C. It learns your habits over time, and uses them to "intelligently" sort your assorted todo lists. __todocmd__ records information on your todos, like the assigned tags and priorities, to automatically arrange your todo list (FEATURE UNDER DEVELOPMENT). The user has the ability to sort todos based on priority, tags, or let __todocmd__ automatically sort their todos for them. __todocmd__ was developed to make managing your todos and schedule easier, allowing the user to spend more time forcusing on important work.

# Getting Started #
### Installation ###
### Commands ###
##### Basic IO Commands: #####
- __Creating a todo:__ `todocmd -a <todo>`
- __Completing a todo:__ `todocmd -c <index>`
- __Removing a todo:__ `todocmd -r <index>`

##### Todo Metadata Commands: #####
- __Adding a priority:__ append `-p <priority>` on todo creation
- __Adding tags:__ append `-t <tags>` on todo creation; seperate tags with spaces
- _**NOTICE:** ORDER OF PRIORITY AND TAG COMMANDS DOES NOT MATTER_
 
##### Listing Commands #####
- __List todos (default):__ `todocmd -l`
- __List todos (by priority):__
- __List todo (by tag):__
 
# Contributing #

# Contact Information #
__Walter McLallen__ (@wmclallen):
- Twitter: [@wmclallen](https://twitter.com/wmclallen "wmclallen")
