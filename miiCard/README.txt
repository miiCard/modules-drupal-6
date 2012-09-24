miiCard Drupal module

This module allows users to authenticate to Drupal using their miiCard login (www.miicard.com)

Once installed, go to the admin configuration page to set the consumer details and the miiCard
OAuth and API endpoints.  

A "Sign in with miiCard" link is added to the user login and registration forms as well as the
user login block.  A separate "Sign in with miiCard" block is also provided.

A miiCard tab is added to the user profile page.  This will show a link to "Add miiCard" if the
user hasn't associated a miiCard with their account yet.  Otherwise the profile data retrieved 
from miiCard is displayed.  This miiCard profile data is also provided as a block.  At the time
of development the data returned by the API was not finalised so all profile fields are just 
listed as received.

When a user is returned to Drupal after successfuly authenticating with miiCard, we check to 
see if the miiCard identity has already been associated with a Drupal user.  When the miiCard 
identity is new to Drupal, if the user is not already logged in to Drupal a new external user
is registered with a username of the form "user@miicard.com" where "user" is substituted with 
the miiCard username.  When the miiCard identity is already known to Drupal and the user is not 
yet logged in to Drupal, we log the user in and update the local miiCard profile data.  If the 
user is already logged in to Drupal we update the local miiCard profile data and check the 
current Drupal user is that which has been associated with the miiCard identity.  If necessary 
we log out the Drupal user and log them in with the Drupal user that was previously associated 
with the miiCard identity.

There is a cron task which will go through all the miiCard profiles held in Drupal and attempt 
to refresh them by making calls to the miiCard API re-using OAuth tokens previously generated
when the user last authenticated against the miiCard service. If the API request fails the
OAuth access tokens are expired and not reused again.  The frequency at which attempts are made
to refresh the profile data is configurable through the admin settings page.

