# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'pyMACS'
copyright = '2024, Thomas Halloran'
author = 'Thomas Halloran'

# Dynamic version
import pyMACS
release = pyMACS.__version__

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

# This is processed by Jinja2 and inserted before each notebook
nbsphinx_prolog = r"""
{% set docname = 'docs/source/' + env.doc2path(env.docname, base=None)|string %}

.. raw:: html

    <div class="admonition note">
      This page was generated from
      <a class="reference external" href="https://github.com/bmaranville/pyMACS/tree/main/{{ docname|e }}">{{ docname|e }}</a>.
      [<a href="{{ env.docname.split('/')|last|e + '.ipynb' }}" class="reference download internal" download>Download notebook</a>.]
      <br>
      Interactive online versions:
      <span style="white-space: nowrap;"><a href="https://mybinder.org/v2/gh/bmaranville/pyMACS/{{ env.config.release|e }}?filepath={{ docname|e }}"><img alt="Binder badge" src="https://mybinder.org/badge_logo.svg" style="vertical-align:text-bottom"></a>.</span>
      <span style="white-space: nowrap;">
        <a target="_blank" href="https://colab.research.google.com/github/bmaranville/pyMACS/blob/main/{{ docname|e }}">
            <img src="https://colab.research.google.com/assets/colab-badge.svg" alt="Open In Colab"/>
        </a>
      </span>
     
    </div>

.. raw:: latex

    \nbsphinxstartnotebook{\scriptsize\noindent\strut
    \textcolor{gray}{The following section was generated from
    \sphinxcode{\sphinxupquote{\strut {{ docname | escape_latex }}}} \dotfill}}
"""
