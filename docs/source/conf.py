# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information
import pyMACS
project = 'pyMACS'
copyright = '2024, Thomas Halloran'
author = 'Thomas Halloran'
release = '0.1'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    'sphinx.ext.duration',
    'sphinx.ext.autodoc',
    'sphinx.ext.autosummary',
    'nbsphinx',
    "sphinx_gallery.load_style"
]
templates_path = ['_templates']
exclude_patterns = []



# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'furo'
html_static_path = ['_static']
'''
html_theme_options = {
    "repository_url": "https://github.com/thallor1/pyMACS",
    "use_repository_button": True,
    "use_sidenotes":True,
    "home_page_in_toc": True,
    'collapse_navigation':True}
'''
html_logo = "MACS1.png"
html_title = "pyMACS documentation"